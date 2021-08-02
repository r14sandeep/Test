#include"header.h"
char buf[100];
int fd;
void msg_send(void *p);
void msg_read(void *p);
pthread_t tid1,tid2;
int main(int argc,char **argv)
{
	if(argc<3)
	{
		puts("input formate...server:exe w.k.port no:");
		return 0;
	}
	///////////// SOCKET  //////////////

	puts("creating client socket...");
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd==0)
	{
		perror("socket");
		return 0;
	}
	puts("client socket created..");	

////////////////////////// BIND &CONNECT    //////////////

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
	




	int status;
/*
	while(1)
	{
		puts("enter msg for server");
		memset(buf,0,100);
		gets(buf);
		if(send(fd,buf,100,0)<0)
		{
			perror("recv");
			close(fd);return 0;
		}
		puts("waiting for response");
		memset(buf,0,100);
		status=recv(fd,buf,100,0);
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
		printf("server:%s\n",buf);
		if(strcmp(buf,"quit")==0)
		{
			puts("server formally terminatind connection");
			break;
		}
	}
*/
pthread_create(&tid1,NULL,msg_send,NULL);
pthread_create(&tid2,NULL,msg_read,argv[2]);
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);

	close(fd);
}

void msg_read(void *ip)
{
        while(1)
        {
                puts("waiting for server reply:");
                recv(fd,buf,100,0);
                printf("%s:%s\n",ip,buf);
//              printf("enter reply to client:");
//              gets(buf);
//              send(newfd,buf,100,0);
        }
        pthread_exit(NULL);
}
void msg_send(void *p)
{
        while(1)
        {
                printf("enter reply to server:");
                gets(buf);
                send(fd,buf,100,0);
        }
        pthread_exit(NULL);

}
