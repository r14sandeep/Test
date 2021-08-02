#include"header.h"
main()
{
	int fd,fd1;
	char a[10],rdbuf[1000];
	if(mkfifo("fifo",0600)==-1)
		perror("mkfifio");
	if(mkfifo("fifo1",0600)==-1)
		perror("mkfifio");
	fd=open("fifo",O_RDWR);
	fd1=open("fifo1",O_RDWR);
	puts("enter cmd");
	gets(a);
//	close(1);
//	dup(fd);
//	system("a");
	write(fd,a,strlen(a)+1);
	read(fd1,rdbuf,1000);
	puts(rdbuf);
	close(fd);
	close(fd1);
	

}
