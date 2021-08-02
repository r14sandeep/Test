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
		fcntl(fd2,F_SETFL,O_NONBLOCK);
		fcntl(fd1,F_SETFL,O_NONBLOCK);
		printf("chat2:");
		gets(wr);
		write(fd1,wr,strlen(wr));
		if(read(fd2,rd,100)>=0)
			printf("chat1:%s\n",rd);
	}
	close(fd1);
	close(fd2);

}
