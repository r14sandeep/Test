#include<gst/gst.h>
#include<stdio.h>
int main(int argc,char **argv)
{
	GstElement *element;
	gst_init(&argc,&argv);
	element=gst_element_factory_make("fakesrc","source");
	if(!element)
	{
		g_print("failed");
		return -1;
	}
	gst_object_unref(GST_OBJECT(element));
	return 0;
}
