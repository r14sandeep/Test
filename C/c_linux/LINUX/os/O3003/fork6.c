#include<stdio.h>
#include<stdlib.h>
main()
{
	int i;
	printf("before %d\n",getpid());
	for(i=1;i<=3;i++)
	{	
		if(fork()==0)
		{
			printf("in child %d\n",getpid());
		//	exit(0);
		}
		else
		{	
			printf("in parent %d\n",getpid());
		//	exit(0);
		}
	}
}
