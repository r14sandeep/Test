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
	printf("enter msg:");
	gets(v.mtext);
	v.mtype=1;
	if(msgsnd(id,&v,strlen(v.mtext)+1,0)==-1)
		perror("msgsnd");
}
