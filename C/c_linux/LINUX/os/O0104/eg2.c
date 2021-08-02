#include<stdio.h>
#include<stdlib.h>
main()
{
	if(fork()==0)
	{
		printf("child:%d parent:%d\n",getpid(),getppid());
		printf("delaying for 10 sec\n");
		sleep(5);
		printf("child:%d parent:%d\n",getpid(),getppid());
		//sleep(10);
		printf("exiting \n");
		exit(5);

	}
	else
	{	int v;
		printf("in parent \n");
		wait(&v);
		v>>=8;	
		printf("parent exiting v=%d\n",v);
		exit(0);
	}



}
