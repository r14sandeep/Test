#include<stdio.h>
#include<stdlib.h>
int main()
{
	int v1,v2;
	v1=fork();
	if(v1==0)
	{
		printf("in child %d\n",getpid());
//		sleep(5);
		printf("child exiting\n");
//		exit(getpid());
		exit(1);
	}
	else
	{
		sleep(5);
		printf("in parent\n");
//		sleep(4);
		waitpid(v1,&v2,0);
		v2>>=8;
		printf("%d\n",v2);
		printf("parent exiting\n");
		
	}

}
