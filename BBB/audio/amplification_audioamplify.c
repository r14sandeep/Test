#include<string.h>
#include<gst/gst.h>
#include<glib.h>
#include<unistd.h>

static gfloat ampl=1;
typedef struct _CustomData {
		GstElement *pipeline,*source,*audioamplify,*decoder,*conv,*alsasink,*test,*conv2,*enc,*mux;

		GMainLoop *loop;
		GstBus *bus;
		guint bus_watch_id;
		gboolean playing;  /* Playing or Paused */
		gdouble rate;      /* Current playback rate (can be negative) */						
} CustomData;

CustomData data;

static gboolean
bus_call(GstBus *bus,GstMessage *msg,gpointer data)
{
		GMainLoop *loop=(GMainLoop *) data;
		switch (GST_MESSAGE_TYPE(msg))
		{
				case GST_MESSAGE_EOS:
						g_print("End of stream\n");
						g_main_loop_quit(loop);
						break;
				case GST_MESSAGE_ERROR:
						{
								gchar *debug;
								GError *error;
								gst_message_parse_error(msg,&error,&debug);
								g_free(debug);
								g_printerr("Error:%s\n",error->message);
								g_error_free(error);
								g_main_loop_quit(loop);
								break;
						}
				default:
						break;
		}
		return TRUE;
}
static void on_pad_added(GstElement *element, GstPad *pad , gpointer data)
{
		GstPad *sinkpad;
		GstElement *decoder=(GstElement *)data;
		
		sinkpad=gst_element_get_static_pad(decoder, "sink");
		//	sinkpad=gst_element_get_static_pad(osssink,"sink");
		gst_pad_link(pad,sinkpad);
		gst_object_unref(sinkpad);
}

static int change_amplify(CustomData *data,gfloat i)
{
		gfloat lamplify;
		ampl=i;

		g_object_set(G_OBJECT(data->audioamplify),"amplification",ampl,NULL);
		g_object_get(data->audioamplify,"amplification",&lamplify,NULL);

		if(ampl==lamplify)
			return 1;
		else
			return 0;
}


void disable_mainloop()
{
	g_main_loop_unref(data.loop);
	g_main_loop_quit(data.loop);
	gst_element_set_state (data.pipeline, GST_STATE_NULL);
	gst_object_unref (data.pipeline);
	

}



gint start()
{

		GstStateChangeReturn ret;

		/*initialization*/
		gst_init(NULL,NULL);
		memset (&data, 0, sizeof (data));
		data.loop = g_main_loop_new (NULL, FALSE);

		data.pipeline=gst_pipeline_new("mp3player");
		data.source=gst_element_factory_make("filesrc","source");
		if(!data.source){
				g_print("Failed to create source\n");
				return -1;
		}
		data.decoder=gst_element_factory_make("decodebin","audiomp3decoder");
		if(!data.decoder){
				g_print("failed to create decoder\n");
				return -1;
		}

		data.audioamplify=gst_element_factory_make("audioamplify","audioamplify amplification");
		if(!data.audioamplify){
				g_print("failed to create audioamplify\n");
				return -1;
		}
		data.conv=gst_element_factory_make("audioconvert","audioconverter");
		if(!data.conv){
				g_print("Failed to create audio converter\n");
				return -1;
		}
		data.conv2=gst_element_factory_make("audioconvert","audioconverter2");
		if(!data.conv2){
				g_print("Failed to create audio converter2\n");
				return -1;
		}
		data.alsasink=gst_element_factory_make("filesink","audiosink");
		if(!data.alsasink){
				g_print("Failed to create audiosink\n");
				return -1;
		}
		data.enc=gst_element_factory_make("vorbisenc","enc");
		if(!data.enc){
				g_print("Failed to create enc\n");
				return -1;
		}
		data.mux=gst_element_factory_make("oggmux","mux");
		if(!data.mux){
				g_print("Failed to create mux\n");
				return -1;
		}

		if(!data.pipeline|| !data.source || !data.decoder || !data.audioamplify || !data.conv || !data.alsasink)
		{
				g_printerr("One element could not be created. Exiting\n");
				return -1;
		}
		/* setting up the pipeline*/
		g_object_set (G_OBJECT (data.source),"location","./song.mp3",NULL);
		g_object_set (G_OBJECT (data.alsasink),"location","song_amplify.ogg",NULL);
		/** adding message handler**/
		data.bus=gst_pipeline_get_bus(GST_PIPELINE(data.pipeline));

		data.bus_watch_id=gst_bus_add_watch(data.bus,bus_call,data.loop);
		gst_object_unref(data.bus);

		/** adding all elements to the pipeline**/
		gst_bin_add_many(GST_BIN(data.pipeline),data.source,data.decoder,data.audioamplify,data.conv,data.conv2,data.alsasink,data.enc,data.mux,NULL);

		/** Linking all the elements**/
		gst_element_link(data.source,data.decoder);
		gst_element_link(data.decoder,data.conv);
		gst_element_link(data.conv,data.audioamplify);

		
		gst_element_link(data.audioamplify,data.conv2);
		gst_element_link(data.conv2,data.enc);
		gst_element_link(data.enc,data.mux);	
		gst_element_link(data.mux,data.alsasink);

		g_signal_connect(data.decoder, "pad-added", G_CALLBACK(on_pad_added),data.conv);   
		g_signal_connect(data.conv, "pad-added", G_CALLBACK(on_pad_added),data.audioamplify);   
		g_signal_connect(data.audioamplify, "pad-added", G_CALLBACK(on_pad_added),data.conv2);   



		g_signal_connect(data.conv2, "pad-added", G_CALLBACK(on_pad_added),data.enc);
		g_signal_connect(data.enc, "pad-added", G_CALLBACK(on_pad_added),data.mux);
		g_signal_connect(data.mux,"pad-added",G_CALLBACK(on_pad_added),data.alsasink);
		ret=gst_element_set_state(data.pipeline,GST_STATE_PLAYING);
		if (ret == GST_STATE_CHANGE_FAILURE) {
				g_printerr ("Unable to set the pipeline to the playing state.\n");
				gst_object_unref (data.pipeline);
				return -1;
		}
		/* Create a GLib Main Loop and set it to run */
		data.loop = g_main_loop_new (NULL, FALSE);
		gint p;
		gfloat i=0;
		for(i=1;i<=10;i++)
		{
			p = change_amplify(&data,i);
			sleep(1);
			if(p==0)
				break;		
		}
		//p = change_amplify(&data,0);
		/**Iterate**/
		
		alarm(15);
		signal(SIGALRM,disable_mainloop);
		
		g_main_loop_run(data.loop);

		/***removing****/
		
		return p;
}

