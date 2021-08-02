#include <gst/gst.h>
#include <glib.h>
#include<unistd.h>
	static gboolean
bus_call (GstBus *bus,GstMessage *msg,gpointer data)

{
	GMainLoop *loop = (GMainLoop *) data;
	switch (GST_MESSAGE_TYPE (msg)) {
		case GST_MESSAGE_EOS:
			g_print ("End of stream\n");
			g_main_loop_quit (loop);
			break;
		case GST_MESSAGE_ERROR: {
						gchar *debug;
						GError *error;
						gst_message_parse_error (msg, &error, &debug);
						g_free (debug);
						g_printerr ("Error: %s\n", error->message);
						g_error_free (error);
						g_main_loop_quit (loop);
						break;
					}
		default:
					break;
	}
	return TRUE;
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

int main (int argc,char *argv[])
{
	
	gint64 position;
  GstEvent *seek_event;
gdouble rate;      /* Current playback rate (can be negative) */

	
GstElement *video_sink=NULL;

	GMainLoop *loop;
	GstElement *pipeline;
	GstElement *source;
	GstElement *videoconv;
	GstElement *audioconv;
	GstElement *decoder;
	GstElement *audiosink;
	GstElement *videosink;
        GstElement *resample;
	GstBus *bus;
	guint bus_watch_id;
	/* Initialisation */
	gst_init (&argc, &argv);

	loop = g_main_loop_new (NULL, FALSE);
	/* Check input arguments */
	if (argc != 2) {
		g_printerr ("Usage: %s <mp4> filename>\n", argv[0]);
		return -1;
	}
	/* Create gstreamer elements */
	pipeline = gst_pipeline_new ("videoplayer");
	source = gst_element_factory_make ("filesrc", "/home/bolludiv/gstreamer/video.mp4");

	if(!source){
		g_print("Failed to create source\n");
		return -1;
	}

	decoder = gst_element_factory_make ("decodebin", "video decoder");
	//decoder = gst_element_factory_make ("dvdec", "video decoder");
	if(!decoder){
		g_print("Failed to create  video decoder\n");
		return -1;
	}

	videoconv = gst_element_factory_make ("videoconvert", "video conversion");
        if(!videoconv){
                g_print("Failed to create videoconverter\n");
                return -1;
        }



	videosink = gst_element_factory_make ("xvimagesink", "video output");
	if(!videosink){
		g_print("Failed to create videosink\n");
		return -1;
	}

	audioconv = gst_element_factory_make ("audioconvert", "audio conversion");
	if(!audioconv){
		g_print("Failed to create audio conv\n");
		return -1;
	}

	resample = gst_element_factory_make ("audioresample", "audio sample");
        if(!resample){
                g_print("Failed to create audio sample\n");
                return -1;
        }

	
	audiosink = gst_element_factory_make ("alsasink", "audio-output");
        if(!audiosink){
                g_print("Failed to create audio sink\n");
                return -1;
        }



	if (!pipeline || !source || !decoder || !videoconv || !videosink || !audioconv || !resample || !audiosink) {
		g_printerr ("One element could not be created. Exiting.\n");
		return -1;
	}
	/* Set up the pipeline */
	/* we set the input filename to the source element */
	g_object_set (G_OBJECT (source), "location", argv[1], NULL);
	/* we add a message handler */
	bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
	g_print("bus created\n");
	bus_watch_id=gst_bus_add_watch (bus, bus_call, loop);
	gst_object_unref (bus);
	/* we add all elements into the pipeline */
	gst_bin_add_many (GST_BIN (pipeline),
			source,decoder,audiosink,videosink,resample,audioconv,videoconv,NULL);
	/* we link the elements together */
	gst_element_link (source, decoder);
	gst_element_link (decoder,videoconv);
	gst_element_link (videoconv,videosink);
	//gst_element_link (decoder,videosink);
	gst_element_link (decoder,audioconv);
        gst_element_link (audioconv, resample);

	gst_element_link (resample,audiosink);



	g_signal_connect (decoder, "pad-added", G_CALLBACK (on_pad_added), videoconv);
	g_signal_connect(videoconv, "pad-added", G_CALLBACK(on_pad_added), videosink);   
	//g_signal_connect (decoder, "pad-added", G_CALLBACK (on_pad_added), videosink);

	g_signal_connect(decoder,"pad-added",G_CALLBACK(on_pad_added),audioconv);
	g_signal_connect(audioconv,"pad-added",G_CALLBACK(on_pad_added),resample);
        g_signal_connect(resample,"pad-added",G_CALLBACK(on_pad_added),audiosink);



	/* Set the pipeline to "playing" state*/
	g_print ("Now playing: %s\n", argv[1]);
	gst_element_set_state (pipeline, GST_STATE_PLAYING);	
	sleep(4);

	if (!gst_element_query_position (pipeline, GST_FORMAT_TIME, &position)) {
    g_printerr ("Unable to retrieve current position.\n");
    //return 0;
  }

	rate=0.25;
	seek_event = gst_event_new_seek (rate, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_ACCURATE,
        GST_SEEK_TYPE_SET, position, GST_SEEK_TYPE_SET, -1);
	g_print("%d\n",seek_event);
	if(videosink==NULL)
	{
		g_print("video_sink\n");
		//g_object_get (G_OBJECT(pipeline), "video-sink", &video_sink, NULL);
		g_object_get (pipeline, "videosink", &videosink, NULL);
	}
	gboolean result;
	result=gst_element_send_event (videosink, seek_event);
	if(!result)
		g_warning("event failed\n");
	//gst_element_set_state (pipeline, GST_STATE_PLAYING);
	//g_print("PLAY\n");

	/* Iterate */
	g_print ("Running...\n");
	g_main_loop_run (loop);
	/* Out of the main loop, clean up nicely */
	g_print ("Returned, stopping playback\n");
	gst_element_set_state (pipeline, GST_STATE_NULL);
	g_print("Unreferencing the pipeline\n");
	g_source_remove(bus_watch_id);
	g_main_loop_unref(loop);
	return 0;
} 


