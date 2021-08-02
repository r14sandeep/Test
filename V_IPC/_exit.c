#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int v1;
	v1=fork();
	printf("in\n");
	if(v1==0)
	{
		printf("in child %d,pid %d\n",getpid(),getppid());
		sleep(6);
		printf("in child %d,pid %d\n",getpid(),getppid());
		while(1);
		printf("child exiting\n");
		wait(0);		
//		_exit(0);
	}
	else
	{
		printf("in parent\n");
//		wait(0);
//		sleep(3);
//		while(1);
		printf("parent exiting\n");
		_exit(0);
//		while(1);
	}
//	printf("end\n");

}
