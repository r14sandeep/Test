#include"header.h"
void *bt_cal(void*p)
{

	scaned_data=bt_scan(dev_id,&num_resp);
	Process_BT_data(num_resp,scaned_data,sock);
}
