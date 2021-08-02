#include<stdio.h>
main()
{
	printf("process %d %d\n",getpid(),getppid());
	system("ps -l");	
	
}
