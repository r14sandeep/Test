#include<gst/gst.h>
int main(int argc,char **argv)
{
	GstElementFactory *factory;
	GstElement *element;
	gst_init(&argc,&argv);
	factory=gst_element_factory_find("fakesrca");
	if(!factory)
	{
		g_print("failed to find factory\n");
		return -1;
	}
	element=gst_element_factory_create(factory,"source");
	if(!element)
	{
		g_print("failed to create element\n");
		return -1;
	}
//	g_print("created element\n");
	gst_object_unref(GST_OBJECT(element));
	gst_object_unref(GST_OBJECT(factory));
	return 0;
}
