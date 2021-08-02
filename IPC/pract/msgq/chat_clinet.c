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
	char rdbuf[100],wrbuf[100];
	id=msgget(1,IPC_CREAT|06600);
//	puts("waiting for client");
		v.mtype=atoi(argv[1]);
	while(1)
	{
		//v.mtype=atoi(argv[1]);
		printf("to client:");
		scanf("%s",v.mtext);
		msgsnd(id,&v,strlen(v.mtext)+1,0);
		sleep(1);
		msgrcv(id,&v,100,v.mtype,0);
		printf("serv:%s\n",v.mtext);
	}


}
