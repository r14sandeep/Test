#include"header.h"
main()
{
	int fd1,fd2;
	char wr[100],rd[100];
	if(mkfifo("fifo1",0660)==-1)
		perror("mkfifo");
	if(mkfifo("fifo2",0660)==-1)
		perror("mkfifo");
	fd1=open("fifo1",O_RDWR);	
	fd2=open("fifo2",O_RDWR);	
	while(1)
	{
		fcntl(fd1,F_SETFL,O_NONBLOCK);
		fcntl(fd2,F_SETFL,O_NONBLOCK);
		if(read(fd1,rd,100)>=0)
			printf("chat2:%s\n",rd);
		printf("chat1:");
		gets(wr);
		write(fd2,wr,strlen(wr));
	}
	close(fd1);
	close(fd2);

}
