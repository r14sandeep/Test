#include"header.h"
struct msgbuf
{
	long mtype;
	char mtext[100];


};

int main(int argc,char **argv)
{
	struct msgbuf v;
	int id;
	id=msgget(1,IPC_CREAT|0600);
	if(id==-1)
		perror("msgget");
	printf("id =%d,in process %d\n",id,getpid());
//	char buf[100];
//	printf("enter msg:");
//	gets(buf);
//	v.mtype=0;
	while(1)
	{
		v.mtype=atoi(argv[1]);
		if(msgrcv(id,&v,100,v.mtype,0)==-1)	
			perror("msgrcv");
		puts(v.mtext);
	}

}
