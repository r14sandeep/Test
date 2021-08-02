#include"header.h"
int main()
{
	int v;
	if(fork()==0)
	{
		printf("in child\n");
		sleep(5);
		printf("child exiting\n");
		exit(10);	

	}
	else
	{
		printf("in parent\n");
//		sleep(10);
		wait(&v);///waits for child to exit and collect child's return value
		v>>=8;
		printf("%d\n",v);
		printf("parent exiting\n");
		exit(0);
	
	}



}
