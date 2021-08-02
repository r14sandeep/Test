#include"header.h"
int main()
{
	int fd1,fd2;
	char buff[100];
	if(mkfifo("fifo1",0660)==-1)
		perror("mkfifo");
	if(mkfifo("fifo2",0660)==-1)
		perror("mkfifo");
	fd1=open("fifo1",O_RDWR);
	fd2=open("fifo2",O_RDWR);
	puts("enter cmd:");
	gets(buff);
	write(fd1,buff,strlen(buff)+1);
	read(fd2,buff,100);
	puts(buff);

}
