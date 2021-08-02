#include"header.h"
struct msgbuf
{
	long mtype;
	char mtext[20];
};
main(int argc,char **argv)
{
	struct msgbuf v;
	int id1,id2,id;
	id1=msgget(1,IPC_CREAT|0600);
	//id=msgget(1,IPC_CREAT|0600);
	id2=msgget(2,IPC_CREAT|0600);
	if(id1==-1)
	{
		perror("msgget");return;
	}
	if(id2==-1)
	{
		perror("msgget");return;
	}
	while(1)
	{
	/*if(fork())
	{
		printf("waiting for msg\n");
		v.mtype=atoi(argv[1]);
		if(msgrcv(id2,&v,20,v.mtype,0)==-1)
			perror("msgrcv");
		printf("chat1:%s\n",v.mtext);
		puts("enter msg");
		gets(v.mtext);
		v.mtype=atoi(argv[1]);
		if(msgsnd(id1,&v,strlen(v.mtext)+1,0)==-1)
			perror("msgsnd");
	
	}
	else
	{
		puts("enter msg");
		gets(v.mtext);
		v.mtype=atoi(argv[1]);
		if(msgsnd(id1,&v,strlen(v.mtext),0)==-1)
			perror("msgsnd");
		printf("waiting for msg\n");
		v.mtype=atoi(argv[1]);
		if(msgrcv(id2,&v,20,v.mtype,0)==-1)
			perror("msgrcv");
		printf("chat1:%s\n",v.mtext);

	}*/	
		printf("waiting for msg\n");
		v.mtype=atoi(argv[1]);
		if(msgrcv(id2,&v,20,v.mtype,0)==-1)
			perror("msgrcv");
		printf("chat1:%s\n",v.mtext);
		puts("enter msg");
		gets(v.mtext);
		v.mtype=atoi(argv[1]);
		if(msgsnd(id1,&v,strlen(v.mtext),0)==-1)
			perror("msgsnd");

	}
}
