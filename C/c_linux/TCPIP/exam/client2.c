#include"header.h"
main(int argc,char **argv)
{
	int fd;
	puts("creating client socket");
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
	{
		perror("socket");return;
	}
	puts("client socket created");
	puts("bind& connect");
	struct sockaddr_in servAddr;
	servAddr.sin_family=AF_INET;
	servAddr.sin_port=htons(atoi(argv[1]));
	servAddr.sin_addr.s_addr=inet_addr(argv[2]);
	if((connect(fd,(const struct sockaddr*)&servAddr,sizeof(servAddr))<0))
	{
		perror("connect");return;
	}
	puts("connect success");
	while(1)
	{
	char buf[100];
	int status;
	puts("enter msg to the server");
	memset(buf,0,100);
	gets(buf);
	status=send(fd,buf,100,0);
	if(status<0)
	{
		perror("send");close(fd);return;
	}
	if(status==0)
	{
		puts("abnormal termination");close(fd);return;
	}
	puts("waitng for response");
	if(recv(fd,buf,100,0)<0)
	{
		perror("recv");close(fd);return;
	}
	printf("response is:%s\n",buf);
	if(strcmp(buf,"quit")==0)
	{
		printf("server formally terminated\n");break;

	}
	}
	close(fd);

}

