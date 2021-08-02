#include"header.h"
int main()
{
	int fd1,fd2;
	char wr[100],rd[100];
	fd1=open("fifo1",O_RDWR);
	fd2=open("fifo2",O_RDWR);
	//fcntl(fd2,F_SETFL,O_NONBLOCK);
	while(1)
	{
	//	puts("reading:");
		if(fork()==0)		
		{
			read(fd2,rd,100);
			printf("from server:%s\n",rd);
					
		}
		else
		{
			puts("type:");
			gets(wr);
			write(fd1,wr,strlen(wr)+1);
		}
			

	}
	close(fd1);
	close(fd2);


}
