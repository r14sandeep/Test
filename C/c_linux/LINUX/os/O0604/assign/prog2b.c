#include<stdio.h>
main()
{
	printf("%d \n",getpid());
	if(fork()==0)
		printf("%d %d\n",getpid(),getppid());
		
	else
	{
		if(fork()==0)
			printf("%d %d\n",getpid(),getppid());
	else
		if(fork()==0)
			printf("%d %d\n",getpid(),getppid());
		
	}

}
