#include<stdio.h>
main()
{
	printf("process:%d %d\n",getpid(),getppid());
	if(!(printf("if\n")))
		printf("hi");	
	else
	printf("else\n");
}
