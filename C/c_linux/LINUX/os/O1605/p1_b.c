#include"header.h"
main()
{
	open("testfile",O_CREAT|O_WRONLY|O_APPEND,0600);
	printf("process %d parent %d\n",getpid(),getppid());
	fcntl(3,F_SETFD,1);
	if(execlp("./p2","./p2",NULL)==-1)
		perror("execlp");
	printf("in p1\n");
}
