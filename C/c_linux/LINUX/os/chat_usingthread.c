#include"header.h"
#include<pthread.h>
pthread_t tid1,tid2;
char rdbuf[100],wrbuf[100];
void *job2(void *p)
{
	int fd2,fd1;
	while(1)
	{
	fd2=open("fifo",O_RDWR);
	write(fd2,wrbuf,strlen(wrbuf)+1);
	printf("job1:%s\n",rdbuf);
	printf("enter msg to job1:");
	getchar();
	gets(wrbuf);
	fd1=open("fifo1",O_RDWR);
	read(fd1,rdbuf,100);
	sleep(1);
		
	}	
}
/*void *job1(void *p)
{
	int fd1,fd2;
	while(1)
	{
	fd2=open("fifo",O_RDONLY);
	read(fd2,str,strlen(str));
	printf("job2:%s\n",str);
	fd1=open("fifo1",O_WRONLY);
	printf("enter msg to job2:");
	getchar();
	gets(str);
	write(fd1,str,strlen(str)+1);
	sleep(1);
	}

}*/	
main()
{
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifo");
	if(mkfifo("fifo1",0660)==-1)
		perror("mkfifo1");
//	pthread_create(&tid1,NULL,job1,NULL);
	pthread_create(&tid2,NULL,job2,NULL);
//	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}
