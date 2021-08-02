#include"header.h"
struct tag
{
	long mtype;
	char rdtext[100],wrtext[100];

};
int main(int argc,char **argv)
{
	int id;
	struct tag v;
	id=msgget(1,IPC_CREAT|0600);
	printf("server is waiting for input:\n");
	while(strcmp(v.rdtext,"exit")!=0)
	{
		v.mtype=atoi(argv[1]);
		msgrcv(id,&v,100,v.mtype,0);
		printf("msg from client:%s\n",v.rdtext);
		printf("send reply:");
		gets(v.wrtext);
		msgsnd(id,&v,strlen(v.wrtext)+1,0);
		
		
	}

}
