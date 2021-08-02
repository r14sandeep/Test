#include"header.h"
main()
{
	int fd;
	char b[1000];
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifio");
	fd=open("fifo",O_RDWR);
//	puts("enter b");
//	gets(b);
//	write(fd,b,strlen(b)+1);	
	//puts(a);
	read(fd,b,strlen(b));
	system("wc b");
}
