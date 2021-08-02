#include<stdio.h>
main()
{
	int i;
	if(fork())
	{
		printf("in parent %d\n",getpid());
		sleep(10);
	}
	else
	{
		printf("in child %d\n",getppid());
		sleep(1);
		
	}

}
