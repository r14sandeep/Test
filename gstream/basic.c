#include <gst/gst.h>

int main(int argc, char *argv[]) {
  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

  /* Initialize GStreamer */
  gst_init (&argc, &argv);

  /* Build the pipeline */
//  pipeline = gst_parse_launch ("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm", NULL);
//  pipeline = gst_parse_launch ("playbin uri=file:///home/ghanasan/Desktop/Big.mp4", NULL);



GMainLoop *loop;
	GstElement *source;
	GstElement *decoder;
	GstElement *conv;
	GstElement *alsasink;
	guint bus_watch_id;
	/*initialization*/
	loop=g_main_loop_new(NULL,FALSE);


	pipeline=gst_pipeline_new("mp3player");
	source=gst_element_factory_make("filesrc","filesource");
	if(!source){
		g_print("Failed to create source\n");
		return -1;
	}
	decoder=gst_element_factory_make("mad","audiomp3decoder");
	if(!decoder){
		g_print("failed to create decoder\n");
		return -1;
	}
	conv=gst_element_factory_make("audioconvert","audioconverter");
	if(!conv){
		g_print("Failed to create audio converter\n");
		return -1;
	}
	alsasink=gst_element_factory_make("alsasink","audiosink");
	if(!alsasink){
		g_print("Failed to create audiosink\n");
		return -1;
	}

	if(!pipeline|| !source || !decoder || !conv || !alsasink)
	{
		g_printerr("One element could not be created. Exiting\n");
		return -1;
	}
	/* setting up the pipeline*/
	g_object_set (G_OBJECT (source),"location",argv[1],NULL);
	/** adding message handler**/
	bus=gst_pipeline_get_bus(GST_PIPELINE(pipeline));
	g_print("bus created\n" );
	bus_watch_id=gst_bus_add_watch(bus,bus_call,loop);
	//gst_object_unref(bus);

	/** adding all elements to the pipeline**/
	gst_bin_add_many(GST_BIN(pipeline),source,decoder,conv,alsasink,NULL);

	/** Linking all the elements**/

	//gst_element_link(source,decoder);
	gst_element_link(source,decoder);
	gst_element_link(decoder,conv);
	gst_element_link(conv,alsasink);


  /* Start playing */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);
//  gst_element_set_state (pipeline, GST_STATE_PAUSED);

  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);
  msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* Free resources */
  if (msg != NULL)
    gst_message_unref (msg);
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);
  return 0;
}

