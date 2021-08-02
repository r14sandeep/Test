#include"header.h"
int main()
{
	int pid,val=0;
	if(fork()==0)
	{
		puts("in child");
		sleep(10);
		puts("child exiting");
//		exit(0);
	}
	else
	{
		puts("in parent");
		sleep(1);
		puts("parent exiting");
//		exit(0);
	}
}
