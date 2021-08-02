#include"header.h"
int main(int argc,char **argv)
{
	int fd,fd2;
	fd=open(argv[1],O_RDWR);
	printf("fd=%d\n",fd);
	close(1);
	dup(fd);
//	dup2(1,fd2);
//	write(fd2,"hello",5);
	system("date");
	printf("fd=%d\n",fd);
}
