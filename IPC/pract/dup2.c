#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
	int fd,fd2;
	fd=open("file2.txt",O_RDWR);
	close(1);
	dup(fd);
	printf("%d\n",fd);
//	dup2(fd,fd2);
	printf("%d\n",fd);
	printf("hello\n");

}
