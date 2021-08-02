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
//			puts("waiting for client msg:");
			read(fd1,rdbuff,100);
			printf("from client:");
			puts(rdbuff);
			exit(0);

		}
		else
		{
			printf("to client:");
			gets(wrbuff);
			write(fd2,wrbuff,strlen(wrbuff)+1);
			wait(0);
		}
	}
}
