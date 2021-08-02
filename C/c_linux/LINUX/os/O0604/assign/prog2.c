#include<stdio.h>
main()
{
	printf("%d \n",getpid());
	if(fork()==0)
	{
		printf("%d %d\n",getpid(),getppid());
		if(fork()==0)
		{	printf("%d %d\n",getpid(),getppid());
			if(fork()==0)
			printf("%d %d\n",getpid(),getppid());
		}
	}
	else
		printf("ppid %d\n",getpid());
}
