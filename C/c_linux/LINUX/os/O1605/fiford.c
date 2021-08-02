#include"header.h"
main()
{
	int fd;
	char rdbuf[20];
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifo");
	fd=open("fifo",O_RDWR);
//	fcntl(fd,F_SETFL,O_NONBLOCK);
	while(1)
	{
	printf("waiting for fifo:\n");
	bzero(rdbuf,20);
	read(fd,rdbuf,20);
	printf("%d:%s\n",getpid(),rdbuf);
	}
	close(fd);

}
