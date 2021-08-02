#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int cnt=0;
main()
{
	int i;
	printf(">>>>>>befor %d\n",getpid);
	for(i=0;i<4;i++)
{	
	fork();
	printf("process: %d \n",getpid());
}	
	
}
