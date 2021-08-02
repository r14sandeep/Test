#include"header.h"
pthread_t tid1,tid2;
	int fd1,fd2;
/*void fifo()
{
if(mkfifo("fifo1",0660)==-1)
	perror("mkfifo");
fd1=open("fifo1",O_RDWR);
if(mkfifo("fifo2",0660)==-1)
	perror("mkfifo");
fd2=open("fifo2",O_RDWR);
}*/
void *cwrite(void *p)
{
	char wrbuf[100];
	while(1){
	puts("enter msg to serv:");
//	gets(wrbuf);
	scanf("%s",wrbuf);
	write(fd1,wrbuf,strlen(wrbuf)+1);
	}
}
void *cread(void *p)
{
	char rdbuf[100];
	while(1){
	read(fd2,rdbuf,100);
	printf("serv:%s\n",rdbuf);
	}
}
int main()
{
//	char wrbuf[100],rdbuf[100];
//	fifo();
if(mkfifo("fifo1",0660)==-1)
	perror("mkfifo");
fd1=open("fifo1",O_WRONLY);
if(mkfifo("fifo2",0660)==-1)
	perror("mkfifo");
fd2=open("fifo2",O_RDONLY);
	while(1)
	{
		pthread_create(&tid1,NULL,cwrite,NULL);
		pthread_create(&tid2,NULL,cread,NULL);
	}
	while(1);
}


