#include"header.h"
main()
{
	int fd;
	char rdbuf[20];
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifo");
	fd=open("fifo",O_RDWR);
	while(1)
	{
	
	printf("waiting for fifo\n");
	bzero(rdbuf,10);////memset(rdbuf,0,10);
	read(fd,rdbuf,9);
	printf("%d:%s\n",getpid(),rdbuf);
	}
	close(fd);

}
