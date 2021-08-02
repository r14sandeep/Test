#include"header.h"
int main()
{
	char wrbuf[20];
	int fd;
	if(mkfifo("fifo",0660)==-1)
	{
		perror("mkfifo");
		
	}
	fd=open("fifo",O_RDWR);
	while(1)
	{
		puts("enter msg:");
		bzero(wrbuf,20);
		gets(wrbuf);
		write(fd,wrbuf,strlen(wrbuf));
		//puts(rdbuf);
//		printf("msg is:%s",rdbuf);
	
	}
}
