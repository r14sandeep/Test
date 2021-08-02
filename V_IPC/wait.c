#include<stdio.h>
#include<stdlib.h>
int main()
{
	int v1,v2;
	v2=fork();
	printf("in\n");
	if(v2==0)
	{
		printf("in child\n");
//		sleep(5);
		printf("child exiting\n");
		exit(0);
	}
	else
	{
		sleep(2);
		printf("in parent\n");
//		wait(&v1);
//		v1>>=8;
		wait(0);		
		printf("parent exiting\n");
//		printf("parent exiting %d\n",v1);
		if(fork()==0)	
		{
			puts("in ch2");
			sleep(5);
			exit(0);
		
		}	


	}
	printf("end\n");
}
