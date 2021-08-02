#include"header.h"
#include<pthread.h>
pthread_t tid1,tid2;
void *job2(void *p)
{
	srand(getpid());
//	while(1)
//	{
		int t;
		printf("in job2\n");
		t=rand()%3+1;
		sleep(t);
//	}
}
void *job1(void *p)
{
	srand(getpid());
//	while(1)
//	{	
		int t;
		printf("in job1\n");
		t=rand()%3+1;
		sleep(t);
//	}
}
int main()
{
//	while(1){
	pthread_create(&tid1,NULL,job1,NULL);
//	pthread_create(&tid2,NULL,job2,NULL);
	puts("hi");
//}//	
	while(1);
}
