#include"header.h"
main(int argc,char **argv)
{
	if(argc<2)
	{
		puts("input formate...server:exe w.k.port no:");
		return 0;
	}
	///////////// SOCKET  //////////////

	puts("creating client socket...");
	int fd;
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd==0)
	{
		perror("socket");
		return 0;
	}
	puts("client socket created..");	

////////////////////////// BIND  //////////////

	puts("binding & connecting");
	struct sockaddr_in clAddr;
	clAddr.sin_family=AF_INET;
	clAddr.sin_port=htons(atoi(argv[1]));
	clAddr.sin_addr.s_addr=inet_addr(argv[2]);
	//INADDR_ANY
//	if(connect(fd,(const struct sockaddr *)&servAddr,sizeof(servAddr))<0)	




	if(connect(fd,((const struct sockaddr *)&clAddr),sizeof(clAddr))<0)
	{
		perror("connect");	
		return 0;
	}
	puts("connect success");
	




	char buf[100];
	int status,a,i;
	
	puts("enter msg for server");
	/*puts("enter min,max");
	for(i=0;i<2;i++)
	{
		scanf("%d",&a);
		buf[i]=a;
	}*/
	memset(buf,0,100);
	gets(buf);
	if(send(fd,buf,100,0)<0)
	{
		perror("recv");
		close(fd);return 0;


	}
	puts("waiting for response");
	memset(buf,0,100);
	while(1)
	{
	printf("*****\n");
	status=recv(fd,buf,100,0);
	if(strcmp(buf,"quit")==0)
		break;
	if(status<0)
	{
		perror("recv");
		close(fd);return 0;
	}
	else if(status==0)
		{
			puts("server abnormally terminated\n");
			close(fd);return 0;
		}
	//if(strcmp(buf,"quit")==0)
	//	break;
	printf("recv...: %s\n",buf);
	}
	close(fd);
}
