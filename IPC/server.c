#include"header.h"
int main()
{
	int fd1,fd2;
	char rdbuf[20];
	if(mkfifo("fifo1",0660)==1)
		perror("mkfifo");
	if(mkfifo("fifo2",0660)==1)
		perror("mkfifo");
	fd1=open("fifo1",O_RDWR);
//	fd2=open("fifo2",O_WRONLY);
	read(fd1,rdbuf,20);
	close(1);
	dup(fd1);
	system(rdbuf);
	close(fd1);;
	


}
