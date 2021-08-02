#include"header.h"
struct msgbuf
{
	long mtype;
	char mtext[20];
};
main()
{
	struct msgbuf v;
	int id;
	id=msgget(1,IPC_CREAT|0600);
	if(id==-1)
	{
		perror("msgget");
		return;
	}
	printf("about to read msg\n");
	v.mtype=0;
	if(msgrcv(id,&v,20,v.mtype,0)==-1)	
		perror("msgrcv");
	else
	{
		printf("msg:%s\n",v.mtext);
	}

}
