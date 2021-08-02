#include"header.h"
#include<pthread.h>
pthread_t tid1,tid2;
int v=1;
void *job2(void *p)
{
	printf("in job2\n");
	printf("in job2 v=%d\n",v);
	sleep(2);
	v++;
	printf("in job2 v(inc)=%d\n",v);	
	printf("exiting job2\n");
	pthread_exit(0);
	
}
void *job1(void *p)
{
	int i=15,*q;
	q=&i;
	printf("in job1\n");
	sleep(1);
	printf("in job1 v=%d\n",v);
	v+=10;
	printf("in job2 v(+10)=%d\n",v);	
	printf("exiting job1\n");
	pthread_exit(q);
}	
main()
{
	int *i;
	pthread_create(&tid1,NULL,job1,NULL);
	pthread_create(&tid2,NULL,job2,NULL);
	pthread_join(tid1,i);
	printf("i:%d\n",*i);
	pthread_join(tid2,NULL);
}
