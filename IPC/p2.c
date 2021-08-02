#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("%d\n",getpid());
	system("./p1&");
	sleep(1);
	printf("returning\n");
	system("ls");


}
