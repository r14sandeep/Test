#include<stdio.h>
#include<unistd.h>
main()
{
	int ret;
	printf("11..process %d %d\n",getpid(),getppid());
	ret=fork();
	printf("2222..\n");
	if(ret)
		execlp("ls","ls",NULL);
	else
		execlp("date","date",NULL);
}
