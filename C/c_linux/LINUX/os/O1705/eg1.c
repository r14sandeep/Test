#include"header.h"
main()
{
	int fd;
	char a[1000];
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifio");
	fd=open("fifo",O_RDWR);
	close(1);
	dup(fd);
	system("ls");
//	read(fd,a,9);	
//	puts(a);
//	system("ls|wc");
//	write(fd,a,strlen(a)+1);
	
}
