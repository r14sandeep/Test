#include<stdio.h>
#include<stdlib.h>
int i=1;
main()
{
	i++;
	printf("i=%d\n",i);
	if(fork()==0)
	{
		sleep(1);
		printf("in child i=%d\n",i);
		sleep(1);
		printf("in child i=%d\n",i);
		sleep(4);
		exit(0);
		
	}
	else
	{
		int v;
		printf("in parent i=%d\n",++i);
		wait(&v);
		//v>>=5;
		sleep(10);
		printf("in parent i=%d\n",i);
		exit(0);	
	}	
	
}

