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
		printf("about tp read\n");
		v.mtype=atoi(argv[1]);
		if(msgrcv(id,&v,20,v.mtype,0)==-1)
			perror("msgrcv");
		else
			printf("msg:%s\n",v.mtext);
	
	}
}
