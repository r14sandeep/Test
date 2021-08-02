#include<stdio.h>
#include<stdlib.h>
int main()
{
	int v1;
	v1=vfork();
	printf("hi\n");
	if(v1==0)
	{
		printf("child\n");
//		sleep(2);
		printf("child exiting\n");
//		exit(0);
	}
	else
	{
		printf("parent\n");
//		wait(0);
		printf("parent exiting\n");
	}
}
