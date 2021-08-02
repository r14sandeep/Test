#include"header.h"
#include<pthread.h>
pthread_t tid1,tid2;
char str[100];
/*void *job2(void *p)
{
	while(1)
	{
	printf("job1:%s\n",str);
	printf("enter msg to job1:");
	getchar();
	gets(str);
	sleep(1);
		
	}	
}*/
void *job1(void *p)
{
	while(1)
	{
	printf("job2:%s\n",str);
	printf("enter msg to job2:");
	getchar();
	gets(str);
	sleep(1);
	}

}	
main()
{
	pthread_create(&tid1,NULL,job1,NULL);
//	pthread_create(&tid2,NULL,job2,NULL);
	pthread_join(tid1,NULL);
//	pthread_join(tid2,NULL);
}
