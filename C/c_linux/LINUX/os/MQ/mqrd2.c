#include"header.h"
struct msgbuf
{
	long mtype;
	char mtext[20];
};
main(int argc,char **argv)
{
	struct msgbuf v;
	int id;
	id=msgget(1,IPC_CREAT|0600);
	if(id==-1)
	{
		perror("msgget");
		return;
	}
	while(1)
	{
	printf("about to read msg\n");
	v.mtype=atoi(argv[1]);
	if(msgrcv(id,&v,20,v.mtype,0)==-1)	
		perror("msgrcv");
	else
	{
		printf("msg:%s\n",v.mtext);
	}

	}
}	
