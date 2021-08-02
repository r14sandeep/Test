#include"header.h"
void client_info(struct sockaddr_in,int );
void signal_child(int n);
main(int argc,char **argv)
{
	signal(SIGCHLD,signal_child);
	if(argc<2)
	{
		puts("input formate...server:exe w.k.port no:");
		return 0;
	}


//////////////////     SOCKET      //////////////////////////////

	puts("creating server socket...");
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{
		perror("socket");
		return 0;
	}
	puts("server socket created..");
	puts("using setsockopt for addrs already in use error");
	int var=1;
	if(setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&var,4)<0)
	{
		perror("setsockopt");return 0;
	}


///////////////// BIND   /////////////////

	puts("binding");
	struct sockaddr_in servAddr;
	servAddr.sin_family=AF_INET;
	servAddr.sin_port=htons(atoi(argv[1]));
	servAddr.sin_addr.s_addr=INADDR_ANY;
	//INADDR_ANY
	if(bind(sfd,((const struct sockaddr *)&servAddr),sizeof(servAddr))<0)
	{
		perror("bind");	
		return 0;
	}
	puts("bind success");

////////////////  LISTEN    //////////////////////////

	puts("creating connection queue for ONLY 1");
	if(listen(sfd,1)<0)
	{
		perror("listen");
		return 0;
	}
	puts("listen success");
	struct sockaddr_in cliAddr;

	int client=sizeof(cliAddr),newfd;
	char buf[100];
	int status;
	while(1)
	{
		puts("waiting for connection from any client");
		newfd=accept(sfd,(struct sockaddr *)&cliAddr,&client);
		if(newfd<0)
		{
			perror("accept");break;
		}
		puts("client connected");
		client_info(cliAddr,newfd);	
		if(fork()==0)
		{
			while(1)
			{
				puts("waiting for msg from client");
				memset(buf,0,100);
				status=recv(newfd,buf,100,0);
				if(status<0)
				{
					perror("recv");break;
				}
				else if(status==0)
				{
					puts("client abnormally terminated");
					break;	
				}
				printf("recv:   %s\n",buf);
				printf("echoing back...\n");
				if(send(newfd,buf,100,0)<0)
				{perror("send");break;}
				if(strcmp(buf,"quit")==0)
				{
					puts("client formally terminating connection");
					break;
				}
			}
			close(newfd);exit(0);

		}
	}

	close(sfd);

}

void client_info(struct sockaddr_in cliAddr,int newfd)
{

	char *ip=inet_ntoa(cliAddr.sin_addr);
	unsigned short portno=ntohs(cliAddr.sin_port);
	printf("client's ip:%d\n",ip);
	printf("client's port:%d\n",portno);
	printf("descriptor assigned:%d\n",newfd);

}
void signal_child(int n)
{
	wait(0);
	printf("some chiled exited\n");

}

