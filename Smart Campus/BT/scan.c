
#include"header.h"
//#include"bluetooth.h" 
////
static void cmd_rssi(int dev_id, char *argv);
static int find_conn(int s, int dev_id, long arg);

struct hci_conn_info_req *cr;
/////

void local_time();
void btrssi(char *dest,int dd);

void fun(int n)
{
	return;

}
/*int kbhit(void)
{
 // struct termios oldt, newt;
  int ch;
  int oldf;
  
//  tcgetattr(STDIN_FILENO, &oldt);
 // newt = oldt;
//  newt.c_lflag &= ~(ICANON | ECHO);
//  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
//  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(0, F_SETFL, O_NONBLOCK);
  
  ch = getchar();
  
//  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
//  fcntl(STDIN_FILENO, F_SETFL, oldf);
  
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
  
  return 0;
}
*/
int main(int argc, char **argv)
{
	//inquiry_info *ii = NULL;
	inquiry_info_with_rssi *ii=NULL;

//	read_rssi_rp *rssi_n;
	int max_rsp, num_rsp;
	int dev_id, sock, len, flags;
	int i;
	char addr[19] = { 0 };
	char name[248] = { 0 };
	int fd;
	int8_t rssi;
	//int rssi;
	fd=open("file.txt",O_WRONLY|O_CREAT);
	 
	dev_id = hci_get_route(NULL);
//	printf("dev_id=%d\n",dev_id);
	sock = hci_open_dev( dev_id );
//	printf("sock=%d\n",sock);
	if (dev_id < 0 || sock < 0) 
	{

		perror("opening socket");
	        exit(1);
	}
 //	inquiry_info_with_rssi *rssi_ptr;
	len = 4;
	max_rsp = 255;
	while(1)
//	while(!kbhit())
	{
		flags = IREQ_CACHE_FLUSH;
//		flags = NULL;
		ii = (inquiry_info_with_rssi*)malloc(max_rsp * sizeof(inquiry_info_with_rssi));
//		ii = (inquiry_info_with_rssi*)malloc(max_rsp * sizeof(inquiry_info_with_rssi));
 
		num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
//		num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &rssi_ptr, flags);
//		printf("num_rsp=%d\n",num_rsp);
//		printf("%d\n",ii->bdaddr);  
		if( num_rsp < 0 ) perror("hci_inquiry");
 
		for (i = 0; i < num_rsp; i++)
		{
			ba2str(&(ii+i)->bdaddr, addr);
//			printf("rep:%d\n",(ii+i)->pscan_rep_mode);
//			printf("per:%d\n",(ii+i)->pscan_period_mode);
//			printf("mod:%d\n",(ii+i)->pscan_mode);
//			printf("cl:%d\n",(ii+i)->dev_class[0]);
//			printf("cl:%d\n",(ii+i)->dev_class[1]);
//			printf("cl:%d\n",(ii+i)->dev_class[2]);
//			printf("off:%d\n",(ii+i)->clock_offset);
			memset(name, 0, sizeof(name));
			if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name),name, 0) < 0)
				strcpy(name, "[unknown]");
//			close(1);
//			dup(fd);

///////////
		/*	cr = malloc(sizeof(*cr) + sizeof(struct hci_conn_info));
			bacpy(&cr->bdaddr, &(ii+i)->bdaddr);
			cr->type = ACL_LINK;
			printf("sock:%d\n",sock);
			int a=hci_read_rssi(sock, (cr->conn_info->handle), &rssi, 10);
			if (a< 0) {
				printf("a=%d\n",a);
				perror("Read RSSI failed");
				exit(1);
			}

			printf("RSSI: %d\n", rssi);*/

////////////
			local_time();

//////////////
			//struct hci_conn_info_req *cr;


//	signal(,fun);
			//rssi=read_rssi(addr);
		        //printf("%s %s rssi=%d\n", addr, name,rssi);
			printf("%s %s rssi=%d\n", addr, name,(ii+i)->rssi);
			push_to_database("BT",addr,(ii+i)->rssi,"123456");
			//btrssi(addr,sock);
			//uint16_t handle;
//			hci_read_rssi(sock,(uint8_t)(ii+i)->handle,&rssi,len);
			//hci_read_rssi(sock,handle,&rssi,len);
			//printf("%d\n",rssi);
//			cmd_rssi(sock,addr);			
//			printf("%d\n",rssi);
	
  		}
 
		free( ii );
	}
	close( sock );
	return 0;
}

/////////////

/*void btrssi(char *dest,int dd) {
   // int dev_id = -1;
    struct hci_conn_info_req *cr;
    bdaddr_t bdaddr;
    int8_t rssi;
    //int dd;

    str2ba(dest, &bdaddr);

  //  if (dev_id < 0) {
  //      dev_id = hci_for_each_dev(HCI_UP, find_conn, (long) &bdaddr);
  //      if (dev_id < 0) {
   //          fprintf(stderr, "Not connected.\n");
  //           exit(1);
   //     }
   // }

        //dd = hci_open_dev(dev_id);
        if (dd < 0) {
                perror("HCI device open failed");
                exit(1);
        }

        cr = malloc(sizeof(*cr) + sizeof(struct hci_conn_info));
        if (!cr) {
                perror("Can't allocate memory");
                exit(1);
        }

        bacpy(&cr->bdaddr, &bdaddr);
        cr->type = ACL_LINK;
	printf("dd:%d\n",dd);
        if (ioctl(dd, HCIGETCONNINFO, (unsigned long) cr) < 0) {
                perror("Get connection info failed");
                exit(1);
        }

        if (hci_read_rssi(dd, htobs(cr->conn_info->handle), &rssi, 1000) < 0) {
                perror("Read RSSI failed");
                exit(1);
        }

        printf("RSSI return value: %d\n", rssi);

        free(cr);

        hci_close_dev(dd);

    return;
}*/

//////////////////

void local_time()
{
	char datestring[20],timestring[20];
	time_t t;
	struct tm *tmptr;
        t=time(0);
        tmptr=localtime(&t)     ;
        strftime(datestring,20,"%F",tmptr);
        strftime(timestring,20,"%T",tmptr);
        printf("%s %s ",datestring,timestring);
}



