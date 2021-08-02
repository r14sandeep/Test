#include"header.h"
pthread_t tid1,tid2;
int dev_id,sock;

void *bt(void *p)
{
//	initialise(&dev_id,&sock);
//	write(p[1],&dev_id,4);
//	write(p[1],&sock,4);
	puts("tid1");
	bt_scan(dev_id,sock);


}
void *ble(void *p)
{
	puts("tid2");
//	sleep(1);
//	read(p[0],&dev_id,4);	
//	read(p[0],&sock,4);
	printf("sock:%d\n",sock);
	ble_scan(sock);
}


int main()
{
	//inquiry_info *ii = NULL;
//	read_rssi_rp *rssi_n;
	int max_rsp, num_rsp,p[2];
	pipe(p);
	int dev_id,len, flags;
	char addr[19] = { 0 };
	char name[248] = { 0 };
//	initialise(int *dev_id,int *sock);
	initialise(&dev_id,&sock);
	printf("id:%d sock:%d\n",dev_id,sock);
	puts("main");
	pthread_create(&tid1,NULL,bt,NULL);
	pthread_create(&tid2,NULL,ble,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
		return 0;
}
	


