#include<stdio.h>
int main()
{
	int ret;
	printf("%d\n",getpid());
	ret=fork();
	printf("aaaa\n");
	if(ret)
		execlp("cal","cal",NULL);
	else
		execlp("ls","ls",NULL);

}
