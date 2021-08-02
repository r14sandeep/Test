#include<stdio.h>
#include<unistd.h>
main()
{
	printf("process %d %d\n",getpid(),getppid());
	//system("pwd");
	//system("ls");
	execl("/bin/ls","ls",NULL);
	printf("process p1 exiting\n");
	exit(0);	

}
