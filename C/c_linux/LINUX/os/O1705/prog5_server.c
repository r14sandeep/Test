#include"header.h"
main()
{
	char rdbuf[10];
	int fd,fd1;
	if(fork())
	{
		while(1)
		{
		fd=open("fifo1",O_RDWR);
		fd1=open("fifo2",O_RDWR);
		printf("waiting for client:\n");
		read(fd,rdbuf,10);
		
		close(1);
		dup(fd1);
		system(rdbuf);
		}
	}
	else
	{
		while(1)
		{
		fd=open("fifo1",O_RDWR);
		fd1=open("fifo2",O_RDWR);
		printf("waiting for client:\n");
		read(fd,rdbuf,10);
		close(1);
		dup(fd1);
		system(rdbuf);
		}


	}


}
