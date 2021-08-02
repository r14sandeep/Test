#include<stdio.h>
int main()
{
	int v1;
	printf("in parent pid=%d\n",getpid());
	if(fork()==0)
	{
		printf("child pid=%d\n",getpid());
		printf("child ppid=%d\n",getppid());
	}
	else
	{
		printf("parent pid=%d\n",getpid());
		printf("parent ppid=%d\n",getppid());
	}

}
