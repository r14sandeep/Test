#include"header.h"
int main()
{
	int val=0;
	if(fork()==0)
	{
		puts("in child");
		sleep(5);
		puts("child exiting");
		
	}
	else
	{
		puts("in parent");
		sleep(10);
		puts("parent exiting");
	

	}

}
