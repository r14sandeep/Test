#include"header.h"
int main()
{
	//inquiry_info *ii = NULL;
//	read_rssi_rp *rssi_n;
	int max_rsp, num_rsp,p[2];
	pipe(p);
	int dev_id, sock, len, flags;
	char addr[19] = { 0 };
	char name[248] = { 0 };
//	initialise(int *dev_id,int *sock);

	if(fork()==0)
	{
		initialise(&dev_id,&sock);
		write(p[1],&dev_id,4);
		write(p[1],&sock,4);
		bt_scan(dev_id,sock);


	}
	else
	{
		sleep(1);
		read(p[0],&dev_id,4);	
		read(p[0],&sock,4);
		ble_scan(sock);
	}
	
	return 0;
}
