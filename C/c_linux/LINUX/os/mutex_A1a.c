#include"header.h"
#include<pthread.h>
pthread_mutex_t m1;
pthread_t tid1,tid2,tid3;
//int v=1;
void *job1(void *p)
{
	int i;
	printf("in job1\n");
//	pthread_mutex_lock(&m1);
	for(i=0;i<26;i++)
	{
		printf("%c    ",i+65);
		sleep(1);
	}
//	pthread_mutex_unlock(&m1);
	printf("job1 exiting\n");
}
void *job2(void *p)
{
	int i;
//	printf("in job2\n");
//	pthread_mutex_lock(&m1);
	for(i=0;i<26;i++)
	{
		printf("%d    ",i+1);
		sleep(1);
	}
//	pthread_mutex_unlock(&m1);
	printf("job2 exiting\n");

}
void *job3(void *p)
{
	int i;
//	printf("in job3\n");
//	pthread_mutex_lock(&m1);
	for(i=0;i<26;i++)
	{
		printf("%c\n" ,i+97);
		sleep(1);
	}
//	pthread_mutex_unlock(&m1);
	printf("job3 exiting\n");
}
main()
{
	pthread_mutex_init(&m1,NULL);
	pthread_create(&tid1,NULL,job1,NULL);
	pthread_create(&tid2,NULL,job2,NULL);
	pthread_create(&tid3,NULL,job3,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	pthread_mutex_destroy(&m1);
}
