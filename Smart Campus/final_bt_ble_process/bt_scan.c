#include"header.h"


inquiry_info *bt_scan(int dev_id,int *num_resp)
{	
	int flags,max_resp=255,len=8;
	inquiry_info *scaned_device_struct = NULL;
	flags = IREQ_CACHE_FLUSH;
	scaned_device_struct = (inquiry_info*)malloc(max_resp * sizeof(inquiry_info));
	puts("bt scanning");
	*num_resp = hci_inquiry(dev_id, len, max_resp, NULL, &scaned_device_struct, flags);
//	puts("bt scanning done");
	if( *num_resp < 0 ) perror("hci_inquiry");
//	else return scaned_device_struct;
//printf("dev_id:%d\n",dev_id);printf("rsp:%d\n",*num_resp);
	if(*num_resp>0)
		 return scaned_device_struct;
	else
		return NULL;
}
