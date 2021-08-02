#include<stdio.h>
#include<unistd.h>
main()
{
	printf("befor");
	fork();
	printf("after\n");
	execlp("ls","ls",NULL);

}
