#include"header.h"


void Process_BT_data(int num_resp,inquiry_info *scaned_data,int sock)
{
	int index,rssi;
	char addr[20],name[10],datestr[10],timestr[10];
//	puts("process data");
	printf("resp:%d sock=%d\n",num_resp,sock);
	for(index=0;index<num_resp;index++)
	{
//		puts("name");
		//printf("sock:%s\n",sock);
		ba2str(&(scaned_data+index)->bdaddr, addr);
//		memset(name, 0, sizeof(name));
		//puts("name");

//		if (hci_read_remote_name(sock, &(scaned_data+index)->bdaddr, sizeof(name),name, 1000) < 0)
//			strcpy(name, "[unknown]");
		local_time(datestr,timestr);
		//puts("name done");
	        //printf("%s %s rssi=%d\n", addr, name,rssi);
//		printf("%s %s ", addr, name);
		rssi=read_rssi(addr);
		
		push_to_database(addr,rssi);
		
		//printf("%s %s %s rssi:%d\n",datestr,timestr,addr,rssi);
		//printf("%s %s %s \n",datestr,timestr,addr);
//		puts("after rssi");
	}
	free(scaned_data);				

}
