#include"header.h"
main(int argc,char **argv)
{
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
	sockAddr.sin_addr.s_addr=inet_addr("0.0.0.0");
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
	puts("waiting to connect with any client");
	struct sockaddr_in cliAddr;
	int cle=sizeof(cliAddr),newfd;
	newfd=accept(sfd,(struct sockaddr *)&cliAddr,&cle);
	if(newfd<0)
	{
		perror("accept");return;
	}
	puts("accept success");
	char *ip=inet_ntoa(cliAddr.sin_addr);
	unsigned short port=ntohs(cliAddr.sin_port);
	char buf[100];

	printf("client ip=%s\n",ip);
	printf("port no=%d\n",port);
	


	int status;	
	puts("waitng for msg");
	memset(buf,0,100);
	status=recv(newfd,buf,100,0);
	if(status<0)
	{
		perror("recv");
		close(newfd);close(sfd);return 0;
	}
	if(status==0)
	{
		puts("abnormal termination");
		close(newfd);close(sfd);return 0;
	}
	
	printf("msg from client:%s\n",buf);
	puts("echong back");
	if(send(newfd,buf,100,0)<0)
	{
		perror("send");close(newfd);close(sfd);return;
	}
	close(newfd);close(sfd);

}
