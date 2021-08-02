#include"header.h"


void Process_BT_data(int num_resp,inquiry_info *scaned_data,int sock)
{
	int index,rssi;
	char addr[20],name[10];
	for(index=0;index<num_resp;index++)
	{
		ba2str(&(scaned_data+index)->bdaddr, addr);
		memset(name, 0, sizeof(name));
		if (hci_read_remote_name(sock, &(scaned_data+index)->bdaddr, sizeof(name),name, 0) < 0)
			strcpy(name, "[unknown]");
//		local_time();
		read_rssi(addr);
	        //printf("%s %s rssi=%d\n", addr, name,rssi);
		printf("%s %s rssi=%d\n", addr, name,rssi);
	}				
}
