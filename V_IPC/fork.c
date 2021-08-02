#include<stdio.h>
int  main()
{
	int v1,v2=2,v3=2;
	double d1,d2,d3,d4,d5,d6=3;
	float f1,f2,f3,f4,f5,f6,f7,f8;
	printf("pid=%d\n",getpid());
	printf("pid=%d\n",getppid());
	printf("hi\n");
	fork();
	printf("2\n");


}
