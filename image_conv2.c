#include<gst/gst.h>
#include<stdio.h>
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

int main(int argc,char **argv)
{
	GMainLoop *loop;
	GstElement *pipeline;
	GstElement *vsource,*source,*vsink;
	GstElement *decoder,*encoder;
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
	vsource=gst_element_factory_make("v4l2src","v4l2src");
	if(!source)
	{
		g_print("failed to create source\n");
		return -1;
	}


	vsink = gst_element_factory_make("xvimagesink","videosink");
//	vsink = gst_element_factory_make("autovideosink","videosink");


	if(!vsink)
	{
		g_print("failed to create sink\n");
		return -1;
	}
	if(!pipeline || !vsource || !vsink)
	{
		g_printerr("one element couldn't be created,Exiting\n");
		return -1;
	}

//	g_object_Set(G_OBJECT(source),"location",NULL);
	bus=gst_pipeline_get_bus(GST_PIPELINE(pipeline));
	g_print("bus created\n");
//	bus_watch_id=gst_bus_add_watch(bus,bus_call,loop);
	gst_object_unref(bus);

	gst_bin_add_many(GST_BIN(pipeline),vsource,vsink,NULL);

	gst_element_link(vsource,vsink);
	//g_signal_connect();
	g_print("Video");
	gst_element_set_state(pipeline,GST_STATE_PLAYING);
	gchar ch;
	ch=getchar();

	source=gst_element_factory_make("v4l2src","source");
	encoder=gst_element_factory_make("jpegenc","encoder");
	imagesink=gst_element_factory_make("filesink","sink");
	
//	g_object_set (G_OBJECT (source),"location","/home/imag.jpg",NULL);

	bus=gst_pipeline_get_bus(GST_PIPELINE(pipeline));
        g_print("bus created\n");
        bus_watch_id=gst_bus_add_watch(bus,bus_call,loop);
        gst_object_unref(bus);
	g_print("image captured\n");
	g_object_set (G_OBJECT (imagesink),"location","/home/ghanasan/dev/gstream/gst_proj/image.jpg",NULL);
        gst_bin_add_many(GST_BIN(pipeline),source,encoder,imagesink,NULL);

        gst_element_link(source,encoder);
        gst_element_link(encoder,imagesink);
	gst_element_set_state(pipeline,GST_STATE_PLAYING);
	g_source_remove(bus_watch_id);
	





//	keyhit();
//	while(!keyhit())
//	{
//		g_print("**\n");
//		g_main_loop_run(loop);
//	}
//	image_capture(pipeline);
	//image_capture();

	g_print("exiting\n");
//gst_element_set_state
	gst_element_set_state(pipeline,GST_STATE_NULL);
//	g_source_remove(bus_watch_id);
//	g_main_loop_unref(loop);
	return 0;

}
