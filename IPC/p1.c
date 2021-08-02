#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("%d,%d\n",getpid(),getppid());
	sleep(3);
	system("ls");
	sleep(1);
	system("date");
	sleep(1);
	system("cal");

}
