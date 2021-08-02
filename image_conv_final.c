#include<gst/gst.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
GMainLoop *loop;
static gboolean
bus_call(GstBus *bus,GstMessage *msg,gpointer data)
{
	//GMainLoop *loop=(GMainLoop *) data;
	loop=(GMainLoop *) data;
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

void desable_mainloop()
{
	//GMainLoop *loop;
	//g_print("desable_mainloop\n");
	g_main_loop_unref(loop);
	g_main_loop_quit(loop);

}
static void on_pad_added (GstElement *element,GstPad *pad,gpointer data)
{
	GstPad *sinkpad;

	GstElement *decoder = (GstElement *) data;


	/* We can now link this pad with the vorbis-decoder sink pad */
	g_print ("Dynamic pad created, linking demuxer/decoder\n");
	sinkpad = gst_element_get_static_pad (decoder, "sink");
	gst_pad_link (pad, sinkpad);
	gst_object_unref (sinkpad);
}
void jpg_to_pnm()
{
	GstElement *pipeline;
        GstElement *source,*pngimagesink,*pnmimagesink;
        GstElement *decoder,*pngencoder,*pnmencoder;
        GstBus *bus;
        guint bus_watch_id;

	loop=g_main_loop_new(NULL,FALSE);
        pipeline=gst_pipeline_new("videopipeline2");
        source=gst_element_factory_make("filesrc","source");
        decoder=gst_element_factory_make("gdkpixbufdec","decoder");
	pnmimagesink=gst_element_factory_make("filesink","pnmsink");
	pnmencoder=gst_element_factory_make("pnmenc","pnmencoder");


        bus=gst_pipeline_get_bus(GST_PIPELINE(pipeline));
        //g_print("bus created\n");
        bus_watch_id=gst_bus_add_watch(bus,bus_call,loop);
        gst_object_unref(bus);
        //g_print("pngimage captured\n");
        //g_object_set (G_OBJECT (source),"location","/home/ghanasan/dev/gstream/gst_proj/image.jpg",NULL);
        //g_object_set (G_OBJECT (pnmimagesink),"location","/home/ghanasan/dev/gstream/gst_proj/image.pnm",NULL);
	g_object_set (G_OBJECT (source),"location","./image.jpg",NULL);
        g_object_set (G_OBJECT (pnmimagesink),"location","./image.pnm",NULL);
	gst_bin_add_many(GST_BIN(pipeline),source,decoder,pnmencoder,pnmimagesink,NULL);

        gst_element_link(source,decoder);
	gst_element_link(decoder,pnmencoder);

        gst_element_link(pnmencoder,pnmimagesink);
	//g_signal_connect (decoder, "pad-added", G_CALLBACK (on_pad_added), pnmencoder);
	//g_signal_connect(pnmencoder, "pad-added", G_CALLBACK(on_pad_added), pnmimagesink);
        gst_element_set_state(pipeline,GST_STATE_PLAYING);
	g_main_loop_run(loop);
	g_print("pnm exited\n");
	gst_element_set_state(pipeline,GST_STATE_NULL);

}



void jpg_to_png()
{
	//GMainLoop *loop;
	GstElement *pipeline;
        GstElement *source,*pngimagesink,*pnmimagesink;
        GstElement *decoder,*pngencoder,*pnmencoder;
        GstBus *bus;
        guint bus_watch_id;
  	loop=g_main_loop_new(NULL,FALSE);
        pipeline=gst_pipeline_new("videopipeline2");
        source=gst_element_factory_make("filesrc","source");
        decoder=gst_element_factory_make("gdkpixbufdec","decoder");
	pngencoder=gst_element_factory_make("pngenc","pngencoder");
        pngimagesink=gst_element_factory_make("filesink","pngsink");
	pnmimagesink=gst_element_factory_make("filesink","pnmsink");
	pnmencoder=gst_element_factory_make("pnmenc","pnmencoder");


        bus=gst_pipeline_get_bus(GST_PIPELINE(pipeline));
        //g_print("bus created\n");
        bus_watch_id=gst_bus_add_watch(bus,bus_call,loop);
        gst_object_unref(bus);
        
	g_object_set (G_OBJECT (source),"location","./image.jpg",NULL);
        
	g_object_set (G_OBJECT (pngimagesink),"location","./image.png",NULL);
        
	gst_bin_add_many(GST_BIN(pipeline),source,decoder,pngencoder,pngimagesink,NULL);
	//gst_bin_add_many(GST_BIN(pipeline),source,decoder,pngencoder,pnmencoder,pngimagesink,pnmimagesink,NULL);

        gst_element_link(source,decoder);
	gst_element_link(decoder,pngencoder);

        gst_element_link(pngencoder,pngimagesink);


	//gst_element_link(decoder,pnmencoder);

        //gst_element_link(pnmencoder,pnmimagesink);
	//g_signal_connect (decoder, "pad-added", G_CALLBACK (on_pad_added), pnmencoder);
	//g_signal_connect(pnmencoder, "pad-added", G_CALLBACK(on_pad_added), pnmimagesink);




	//g_signal_connect (decoder, "pad-added", G_CALLBACK (on_pad_added), pngencoder);
	//g_signal_connect(pngencoder, "pad-added", G_CALLBACK(on_pad_added), pngimagesink);   
        gst_element_set_state(pipeline,GST_STATE_PLAYING);
	g_main_loop_run(loop);
	g_print("png exited\n");
	gst_element_set_state(pipeline,GST_STATE_NULL);
	
}

int main(int argc,char **argv)
{
	
	GstElement *pipeline;
	GstElement *vsource,*source,*vsink;
	GstElement *decoder,*jpgencoder,*pngencoder,*pnmencoder;
	GstElement *conv;
	GstElement *alsasink,*imagesink;
	GstBus *bus;
	guint bus_watch_id;
	/*initialization*/
	gst_init(&argc,&argv);
	loop=g_main_loop_new(NULL,FALSE);
/*	if(argc!=2)
	{
		g_printerr("Usage:%s <mp3/ogg filename>\n",argv[0]);
		return -1;
	}
*/	pipeline=gst_pipeline_new("videopipe");
	
	gchar ch;
	g_print("press enter to capture image");
	ch=getchar();

	source=gst_element_factory_make("v4l2src","source");
	jpgencoder=gst_element_factory_make("jpegenc","encoder");
	imagesink=gst_element_factory_make("filesink","sink");
	bus=gst_pipeline_get_bus(GST_PIPELINE(pipeline));
        g_print("bus created\n");
        bus_watch_id=gst_bus_add_watch(bus,bus_call,loop);
        gst_object_unref(bus);
	g_print("image captured\n");
	g_object_set (G_OBJECT (imagesink),"location","/home/ghanasan/dev/gstream/gst_proj/image.jpg",NULL);
        gst_bin_add_many(GST_BIN(pipeline),source,jpgencoder,imagesink,NULL);

        gst_element_link(source,jpgencoder);
        gst_element_link(jpgencoder,imagesink);

	g_signal_connect (jpgencoder, "pad-added", G_CALLBACK (on_pad_added), imagesink);
	gst_element_set_state(pipeline,GST_STATE_PLAYING);
	g_print("exiting\n");
	alarm(1);
	signal(SIGALRM,desable_mainloop);
	g_main_loop_run(loop);
	g_print("jpg mainloop exited\n");
	jpg_to_png();
	jpg_to_pnm();
	gst_element_set_state(pipeline,GST_STATE_NULL);
	//g_source_remove(bus_watch_id);
	
	return 0;

}
