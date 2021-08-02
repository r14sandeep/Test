typedef struct _CustomData {
    jobject app; /* The Java app */
    GstElement *pipeline; /* gStreamer pipeline */
    GstElement *filesrc; /* Input file */
    GstPad *fileblock; /* Used to block filesrc */
    GstElement *ogg; /* Ogg demultiplexer */
    GstElement *vorbis; /* Vorbis decoder */
    GstElement *resample;
    GstElement *convert;
    GstCaps *caps;
    GstElement *rtp; /* RTP packer */
    GstElement *udp; /* UDP sender */
    GMainContext *context; /* GLib Context */
    GMainLoop *main_loop; /* GLib main loop */
    gboolean initialised; /* True after initialisation */
    GstState state; /* Pipeline state */
    GstState target_state; /* What state we want to put the pipeline into */
    gint64 duration; /* Clip length */
    gint64 desired_position; /* Where we want to track to within the clip */
    GstClockTime last_seek_time; /* Used to throttle seeking */
    gboolean is_live; /* Live streams don't need buffering */
} CustomData;


data->pipeline = gst_pipeline_new("pipeline");

data->filesrc = gst_element_factory_make("filesrc", NULL);
if (!data->filesrc) {
    GST_ERROR("Failed to create filesrc.");
    return NULL;
}
g_object_set(G_OBJECT(data->filesrc), "location", "/storage/sdcard0/Music/RunToTheHills.ogg", NULL);

data->fileblock = gst_element_get_static_pad(data->filesrc, "src");

data->ogg = gst_element_factory_make("oggdemux", NULL);
if (!data->ogg) {
    GST_ERROR("Failed to create oggdemux.");
    return NULL;
}

data->vorbis = gst_element_factory_make("vorbisdec", NULL);
if (!data->vorbis) {
    GST_ERROR("Failed to create vorbisdec.");
    return NULL;
}

data->resample = gst_element_factory_make("audioresample", NULL);
if (!data->resample) {
    GST_ERROR("Failed to create audioresample.");
    return NULL;
}

data->convert = gst_element_factory_make("audioconvert", NULL);
if (!data->convert) {
    GST_ERROR("Failed to create audioconvert.");
    return NULL;
}

/*data->caps = gst_caps_new_simple("audio/x-raw-int",
        "channels", G_TYPE_INT, 2,
        "depth", G_TYPE_INT, 16,
        "width", G_TYPE_INT, 16,
        "rate", G_TYPE_INT, 44100);

if (!data->caps) {
    GST_ERROR("Failed to create caps");
    return NULL;
}

data->rtp = gst_element_factory_make("rtpL16pay", NULL);
if (!data->rtp) {
    GST_ERROR("Failed to create rtpL16pay.");
    return NULL;
}

data->udp = gst_element_factory_make("udpsink", NULL);
if (!data->udp) {
    GST_ERROR("Failed to create udpsink.");
    return NULL;
}
g_object_set(G_OBJECT(data->udp), "host", "192.168.100.126", NULL);
g_object_set(G_OBJECT(data->udp), "port", 9001, NULL);
*/

if (!data->ogg || !data->vorbis || !data->resample || !data->convert || !data->caps || !data->rtp || !data->udp) {
    GST_ERROR("Unable to create all elements!");
    return NULL;
}

gst_bin_add_many(GST_BIN(data->pipeline), data->filesrc, data->ogg, data->vorbis,
        data->resample, data->convert, data->caps, data->rtp, data->udp);

/* Link all the elements together */
gst_element_link(data->filesrc, data->ogg);
gst_element_link(data->ogg, data->vorbis);
gst_element_link(data->vorbis, data->resample);
gst_element_link(data->resample, data->convert);
gst_element_link_filtered(data->convert, data->rtp, data->caps);
gst_element_link(data->rtp, data->udp);
