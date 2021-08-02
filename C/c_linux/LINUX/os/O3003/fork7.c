#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
main()
{
	int i;
	printf("befor %d\n",getpid);
	for(i=1;i<=3;i++)
	{
		if(fork()==0)
		{
			printf("in child %d\n",getpid());
			//exit(0);
		}
	}
}
