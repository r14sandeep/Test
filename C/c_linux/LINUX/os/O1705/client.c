#include"header.h"
main()
{
	int fd;
	char wrbuf[10];
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifo");
	fd=open("fifo",O_WRONLY);
	//fd1=open("fifo",O_RDWR);
//	printf("enter cmd:");
//	gets(wrbuf);
//	write(fd,wrbuf,strlen(wrbuf)+1);
	close(1);
	dup(fd);
	execlp("ls","ls",NULL);
	close(fd);


}
