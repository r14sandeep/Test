#include"header.h"
#include<pthread.h>
pthread_t tid1,tid2;
char str[100];
void *job2(void *p)
{
	int fd2;
	while(1)
	{
	fd2=open("fifo",O_RDWR);
	write(fd2,str,strlen(str)+1);
	printf("job1:%s\n",str);
	printf("enter msg to job1:");
	getchar();
	gets(str);
	read(fd2,str,strlen(str));
	sleep(1);
		
	}	
}
void *job1(void *p)
{
	int fd1;
	while(1)
	{
	fd1=open("fifo",O_RDWR);
	read(fd1,str,strlen(str));
	printf("job2:%s\n",str);
	printf("enter msg to job2:");
	getchar();
	gets(str);
	write(fd1,str,strlen(str)+1);
	sleep(1);
	}

}	
main()
{
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifo");
	pthread_create(&tid1,NULL,job1,NULL);
	pthread_create(&tid2,NULL,job2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}
