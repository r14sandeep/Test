#include"header.h"
int main()
{
	char buf[100];
	int fd;
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifio");
	fd=open("fifo",O_RDWR);
	puts("enter cmd:");
	gets(buf);
	write(fd,buf,strlen(buf)+1);
	sleep(1);
	read(fd,buf,100);
	puts(buf);
	
}
