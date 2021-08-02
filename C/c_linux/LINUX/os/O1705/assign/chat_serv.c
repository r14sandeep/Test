#include"header.h"
main()
{
	int fd1,fd2;
	char wrbuf[100],rdbuf[100];
	if(mkfifo("fifo1",0660)==-1)
		perror("mkfifo");
	if(mkfifo("fifo2",0660)==-1)
		perror("mkfifo");
	fd1=open("fifo1",O_RDWR);
	fd2=open("fifo2",O_RDWR);
	while(1)
	{
	if(fork())
	{
		puts("enter msg to chat1:");
		gets(wrbuf);
		write(fd2,wrbuf,strlen(wrbuf)+1);
	}
	
	else
	{
		read(fd1,rdbuf,100);
		printf("chat1:%s\n",rdbuf);

	}

	}
}
