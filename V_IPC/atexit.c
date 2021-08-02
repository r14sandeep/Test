#include<stdio.h>
#include<stdlib.h>
void fun()
{
	printf("in fun\n");
	exit(2);

}
int main()
{
	int v1;
	void (*ptr)(void)=fun;
	if(fork()==0)
	{
		printf("in child\n");
		sleep(5);
		printf("child exiting\n");
//		exit(0);
		atexit(ptr);
	}
	else
	{
		printf("in parent\n");
		wait(&v1);
		v1>>=8;
		
		printf("parent exiting %d\n",v1);
		
	}

}
