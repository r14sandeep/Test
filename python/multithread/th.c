#include<stdio.h>
#include<pthread.h>
pthread_t tid1,tid2;
//pthread_mutex_init;
pthread_mutex_t m1;
int v=1;
void *job2(void *p)
{
	printf("in job2 v=%d\n",v);
	sleep(2);
	v++;
	printf("in job2 v-inc=%d\n",v);
	printf("exiting job2\n");
	pthread_exit(0);
}
void *job1(void *p)
{
	printf("in job1\n");
	pthread_mutex_lock(&m1);
	printf("in job1 v=%d\n",v);
	sleep(1);
	v+=10;
	printf("in job1 v(+10)=%d\n",v);
	printf("exiting job1\n");
	pthread_mutex_unlock(&m1);
	pthread_exit(0);
	
}
int main()
{
	pthread_mutex_init(&m1,NULL);
	pthread_create(&tid1,NULL,job1,NULL);
	pthread_create(&tid2,NULL,job2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_mutex_destroy(&m1);
}
