#include"header.h"
int main()
{
	int fd1,fd2;
	char rdbuff[100],wrbuff[100];
	if(mkfifo("fifo1",0660)==-1)
		perror("mkfifo");
	if(mkfifo("fifo2",0660)==-1)
		perror("mkfifo");
	fd1=open("fifo1",O_RDWR);
	fd2=open("fifo2",O_RDWR);
	while(1)
	{
		if(fork()==0)
		{
			printf("to server:");
			gets(wrbuff);
			write(fd1,wrbuff,strlen(wrbuff)+1);
			exit(0);
		}
		else
		{
//		puts("waiting for server msg:");

		read(fd2,rdbuff,100);
		printf("from serv:");
		puts(rdbuff);
		wait(0);
		}
	}
}
