#include<stdio.h>
#include<unistd.h>
int main()
{
	if(vfork())
	{
		puts("parent");
//		sleep(1);
		puts("parent exiting");
	}
	else
	{
		puts("child");
		sleep(2);
	}
		

}
