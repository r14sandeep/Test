#include"header.h"
main()
{
	int fd,fd1;
	char a[10],rdbuf[500];
	if(mkfifo("fifo",0600)==-1)
		perror("mkfifio");
	if(mkfifo("fifo1",0600)==-1)
		perror("mkfifio");
	fd=open("fifo",O_RDWR);
	fd1=open("fifo1",O_RDWR);
	read(fd,a,10);
	close(1);
	dup(fd1);
	system(a);
	close(fd);
	close(fd1);
	

}
