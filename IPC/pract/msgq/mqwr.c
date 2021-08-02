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
	while(1)
	{
		v.mtype=atoi(argv[1]);
		printf("enter msg:");
		gets(v.mtext);
//		v.mtype=1;
		if(msgsnd(id,&v,strlen(v.mtext)+1,0)==-1)	
			perror("msgsnd");
//	puts(v.mtext);
	}
}
