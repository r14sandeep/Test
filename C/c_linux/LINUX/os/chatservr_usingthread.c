#include"header.h"
#include<pthread.h>
pthread_t tid1,tid2;
char rdbuf[100],wrbuf[100];
void *job1(void *p)
{
	int fd1,fd2;
	while(1)
	{
	fd2=open("fifo",O_RDWR);
	read(fd2,rdbuf,100);
	printf("job2:%s\n",rdbuf);
	fd1=open("fifo1",O_RDWR);
	printf("enter msg to job2:");
	getchar();
	gets(wrbuf);
	write(fd1,wrbuf,strlen(wrbuf)+1);
	sleep(1);
	}

}	
main()
{
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifo");
	if(mkfifo("fifo1",0660)==-1)
		perror("mkfifo1");
	pthread_create(&tid1,NULL,job1,NULL);
//	pthread_create(&tid2,NULL,job2,NULL);
	pthread_join(tid1,NULL);
//	pthread_join(tid2,NULL);
}
