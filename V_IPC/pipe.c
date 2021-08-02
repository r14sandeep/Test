#include<stdio.h>
int main()
{
	int v;
	if(fork()==0)
	{
		puts("in child");
		puts("child exit");
		exit(0);
	}
//	else
//	{
		puts("in parent");
		wait(0);
		puts("parent exit");
//	}

}
