#include"header.h"
main()
{
	int fd;
	char wrbuf[20];
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifo");
	fd=open("fifo",O_RDWR);
	while(1)
	{
		printf("enter msg\n");
//		close(1);
//		dup(fd);
		gets(wrbuf);
		write(fd,wrbuf,strlen(wrbuf)+1);
		printf("%d:%s\n",getpid(),wrbuf);
	}
	close(fd);

}
