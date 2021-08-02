#include"header.h"
main()
{
	//int fd;
	//fd=open("testfile",O_WRONLY);
	printf("process p2:%d\n",getpid());
	write(1,"test\n",5);	
	if(write(3,"abc",3)==-1)
			perror("write in p2");
	else
		printf("write success in p2\n");
}
