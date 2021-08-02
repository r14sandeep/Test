#include<stdio.h>
main()
{
	int ret;
	printf("11..process %d %d",getpid(),getppid());
	ret=fork();
	printf("2222..");
	if(ret)
		printf("if\n");
	else
		printf("else\n");
}
