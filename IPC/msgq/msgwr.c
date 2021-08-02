#include"header.h"
struct msgbuf
{
	long mtype;
	char mtext[20];

};
int main(int argc,char **argv)
{
	int id;
	struct msgbuf v;
	id=msgget(1,IPC_CREAT|0600);	
	if(id==-1)
		perror("msgget");
	printf("id:%d in process %d\n",id,getpid());
	while(strcmp(v.mtext,"exit")!=0)
	{
		puts("enter a msg:");
		gets(v.mtext);
		
		v.mtype=atoi(argv[1]);
		if(msgsnd(id,&v,strlen(v.mtext)+1,0)==-1)
			perror("msgsnd");
		else
			printf("sent msg:%s\n",v.mtext);
	
	}
}
