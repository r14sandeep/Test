#include"header.h"
main()
{
	open("testfile",O_CREAT|O_WRONLY|O_APPEND,0600);
	/////from here on file discriptor 3 is available for p1
	printf("process %d parent %d\n",getpid(),getppid());
	if(execlp("./p2","./p2",NULL)==-1)
		perror("execlp");
	printf("in p1\n");
}
