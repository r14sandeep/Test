#include<stdio.h>
main()
{
	int t;
	srand(getpid());
	t=rand()%10+1;
	printf("%d \n",getpid());
	if(fork()==0)
	{	
		printf("child1:%d %d\n",getpid(),getppid());
		sleep(2);
	}	
	
	else
	{
		if(fork()==0)
		{
		printf("child2:%d %d\n",getpid(),getppid());
		sleep(5);
		}
	else
		if(fork()==0)
		{
			printf("child3:%d %d\n",getpid(),getppid());
			sleep(8);
		}
	}

}
