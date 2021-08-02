#include"header.h"
int main()
{
	inquiry_info *scaned_data;
	int sock,dev_id,num_resp;
	initialise(&dev_id,&sock);
	while(1)
	{	
		scaned_data=bt_scan(dev_id,&num_resp);
		Process_BT_data(num_resp,scaned_data,sock);
	}
}
