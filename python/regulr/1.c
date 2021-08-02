#include<stdio.h>
int main()
{
	if(fork()==0)
	{
		printf("in child\n");
		sleep(4);
		printf("child exited\n");
	}
	else
	{
		printf("in parent\n");
		sleep(6);
		printf("parent  exited\n");
	}


}
