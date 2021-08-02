#include"header.h"
#include<math.h>
#include<pthread.h>
pthread_t tid1,tid2;
int newfd;
char buf[100];
void msg_send(void *p);
void msg_read(void *p);
int main(int argc,char **argv)
{
	if(argc<2)
	{
		puts("input formate...server:exe w.k.port no:");
		return 0;
	}
///////////// SERVER SOCKET  /////////////

	puts("creating server socket...");
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==0)
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
/////////////////// BINDING //////////////////
		
	puts("binding");
	struct sockaddr_in servAddr;
	servAddr.sin_family=AF_INET;
	servAddr.sin_port=htons(atoi(argv[1]));
	servAddr.sin_addr.s_addr=inet_addr("0.0.0.0");
	//INADDR_ANY
	if(bind(sfd,((const struct sockaddr *)&servAddr),sizeof(servAddr))<0)
	{
		perror("bind");	
		return 0;
	}
	puts("bind success");

////////////////// LISTEN   //////////////////

	puts("creating connection queue for ONLY 1");
	if(listen(sfd,1)<0)
	{
		perror("listen");
		return 0;
	}
	puts("listen success");

////////////////////  ACCEPT  ///////////////


while(1)
{
	puts("waiting for connection from any client");
	struct sockaddr_in cliAddr;

	int client=sizeof(cliAddr);
	newfd=accept(sfd,(struct sockaddr *)&cliAddr,&client);
	if(newfd<0)
	{
		perror("accept");return 0;
	}
	puts("client connected");
	char *ip=inet_ntoa(cliAddr.sin_addr);
	unsigned short portNo=ntohs(cliAddr.sin_port);
	printf("client ip:%s\n",ip);
	printf("client's port: %d\n",portNo);
	printf("descriptor assinged :%d\n",newfd);
	char c;
	char temp[100];
	int status,a,b,n,i=0,cnt=0,sum=0,j,k=0,t;
//	puts("waiting for msg from client");
	memset(buf,0,100);
//	status=recv(newfd,buf,100,0);
	/*if(status<0)
	{
		perror("recv");
		close(recv);close(sfd);return 0;
	}
	else if(status==0)
		{
			puts("client abnormally terminated\n");
			close(recv);close(sfd);return 0;
		}
	*/
//		sscanf(buf,"%d%c%d",&a,&c,&b);
		
		/*a=(int)buf[i];
		printf("buf=%d\n",buf[i]);
		b=(int)buf[++i];
		printf("buf=%d\n",buf[i]);
		
		printf("%d %d",a,b);
		*/

/////////////////
/*
		while(1)
		{
		for(i=a;i<=b;i++)
		{
			t=i;
			while(t)
			{
				t=t/10;
				cnt++;
			}
			t=i;
		
			while(t)
			{
				j=t;
				j=j%10;
				t=t/10;
				sum=sum+pow(j,cnt);
			}
				//printf("%d ",cnt);
			if(sum==i)
			{
		//		temp[k++]=i;
				sprintf(temp,"%d",i);
				//printf("i=%d ",i);
			if(send(newfd,temp,100,0)<0)
			{
				perror("send");
				//close(recv);
				close(sfd);return 0;
			}
				//printf("recv...: %s\n",temp);
			}
			cnt=0;		
			sum=0;

		}
	*/
///////////////////
		
	//printf("******\n");	
	//printf("recv...: %s\n",temp);

//////////////////
/*	strcpy(temp,"quit");
	break;

		}
	printf("echoing back ...\n");
*/
/////////////
	/*if(send(newfd,temp,100,0)<0)
	{
		perror("send");
		//close(recv);
		close(sfd);return 0;
	}*/
//	close(recv);
pthread_create(&tid1,NULL,msg_read,ip);
pthread_create(&tid2,NULL,msg_send,NULL);
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);

}

close(sfd);
}



void msg_read(void *ip)
{
	while(1)
	{
//		puts("waiting for client reply:");
		recv(newfd,buf,100,0);
		printf("%s:%s\n",(char *)ip,buf);
//		printf("enter reply to client:");
//		gets(buf);
//		send(newfd,buf,100,0);
	}
	pthread_exit(NULL);
}
void msg_send(void *p)
{
	while(1)
	{
		printf("enter reply to client:");
                gets(buf);
                send(newfd,buf,100,0);
	}
	pthread_exit(NULL);

}
