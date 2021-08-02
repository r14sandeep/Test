#include"header.h"
int main()
{
	int fd1,fd2;
	char cmd[10],buf[1000];
	fd1=open("fifo1",O_RDWR);
//	fd2=open("fifo2",O_RDONLY);
	puts("enter cmd:");
	gets(cmd);
	
	write(fd1,cmd,strlen(cmd)+1);
	sleep(1);	
	read(fd1,buf,1000);
	puts(buf);
	close(fd1);
//	close(fd2);

}
