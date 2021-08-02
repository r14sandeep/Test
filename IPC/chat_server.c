#include"header.h"
int main()
{
	int fd1,fd2;
	char wr[100],rd[100];
	fd1=open("fifo1",O_RDWR);
	fd2=open("fifo2",O_RDWR);
	//fcntl(fd1,F_SETFL,O_NONBLOCK);
	while(1)
	{
		if(fork()==0)
		{
			read(fd1,rd,100);
			printf("from client:%s\n",rd);
		}
		else
		{
			puts("type:");
			gets(wr);
			write(fd2,wr,strlen(wr)+1);
		}		

	}
	close(fd1);
	close(fd2);


}
