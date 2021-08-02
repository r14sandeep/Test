#include<gst/gst.h>
int main(int argc,char **argv)
{
	GstElement *pipeline,*source,*sink,*bin;
	gst_init(&argc,&argv);

	pipeline=gst_pipeline_new("my-pipeline");
	bin=gst_bin_new("my-bin");
	source=gst_element_factory_make("fakesrc","source");
	sink=gst_element_factory_make("fakesink","sink");

	gst_bin_add_many(GST_BIN(bin),source,sink,NULL);
	gst_bin_add(GST_BIN(pipeline),bin);

//	if(!gst_element_link_many(source,filter,sink,NULL))
//		g_warning("failed to link elements\n");
	gst_element_link(source,sink);


}
