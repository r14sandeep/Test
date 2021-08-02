#include"header.h"
void clin_info(struct sockaddr_in cliAddr,int newfd)
{
	char *ip=inet_ntoa(cliAddr.sin_addr);
	unsigned short port=ntohs(cliAddr.sin_port);
	printf("client ip=%s\n",ip);
	printf("port no=%d\n",port);
		

}
void signal_child(int n)
{
	wait(0);
	printf("some child has been exited\n");

}
main(int argc,char **argv)
{
	signal(SIGCHLD,signal_child);
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{
		perror("socket");
		return;
	}
	puts("socket created");
	int v=1;
	if((setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&v,4))<0)
	{
		perror("setsockopt");
		return;
	}
	struct sockaddr_in sockAddr;
	sockAddr.sin_family=AF_INET;
	sockAddr.sin_port=htons(atoi(argv[1]));
	sockAddr.sin_addr.s_addr=INADDR_ANY;
	if((bind(sfd,(const struct sockaddr *)&sockAddr,sizeof(sockAddr)))<0)
	{
		perror("bind");return;
	}
	puts("bind success");
	puts("listen");
	if(listen(sfd,1)<0)
	{
		perror("listen");return;
	}
	puts("listen success");
	struct sockaddr_in cliAddr;
	int cle=sizeof(cliAddr),newfd;
		char buf[100];
		int status;	
	while(1)
	{
		puts("waiting to connect with any client");
		newfd=accept(sfd,(struct sockaddr *)&cliAddr,&cle);
		if(newfd<0)
		{
			perror("accept");break;
		}
		puts("client connected");
		clin_info(cliAddr,newfd);
		if(fork()==0)
		{
		while(1)
		{
			puts("waitng for msg");
			memset(buf,0,100);
			status=recv(newfd,buf,100,0);
			if(status<0)
			{
			perror("recv");
			break;
			}
			if(status==0)
			{
				puts("abnormal termination");
				break;
			}
	
			printf("msg from client:%s\n",buf);
			puts("echong back");
			if(send(newfd,buf,100,0)<0)
			{
				perror("send");break;
			}
			if(strcmp(buf,"quit")==0)
			{
				puts("client formally terminating");break;
			}
		}
		close(newfd);exit(0);
		}
	}
close(sfd);

}
