#include"header.h"
pthread_t tid1,tid2;
int main()
{
	inquiry_info *scaned_data;
	
	int sock,dev_id,num_resp;
	initialise(&dev_id,&sock);
	if (dev_id < 0 || sock < 0)
        {

                perror("opening socket");
                exit(1);
        }

//	printf("sock:%d\n",sock);
	while(1)
	{	
		pthread_create(&tid1,NULL,bt_cal,NULL);
		pthread_create(&tid2,NULL,ble_cal,NULL);
//		pthread_start();
		pthread_join(tid1,NULL);
		pthread_join(tid2,NULL);
//		scaned_data=bt_scan(dev_id,&num_resp);
//		Process_BT_data(num_resp,scaned_data,sock);
	}
}
