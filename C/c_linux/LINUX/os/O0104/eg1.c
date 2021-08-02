#include<stdio.h>
#include<stdlib.h>
main()
{
	if(fork()==0)
	{
		printf("child:%d parent:%d\n",getpid(),getppid());
		printf("delaying for 5 sec\n");
		sleep(2);
		printf("child:%d parent:%d\n",getpid(),getppid());
		printf("exiting \n");
		exit(0);
	}
	else
	{
		printf("in parent \n");
		sleep(20);
		printf("parent exiting\n");
		exit(0);
	}



}
