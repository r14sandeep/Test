#include<stdio.h>
#include<unistd.h>
main()
{
	printf("process %d %d\n",getpid(),getppid());
	execlp("ls","ls","-l","-i","-t",NULL);
	printf("process p1 exiting\n");
	exit(0);	

}
