#include"header.h"
int main(int argc,char **argv)
{
	int fd,fd2;
	fd=open(argv[1],O_RDWR);
	printf("fd=%d\n",fd);
	dup2(1,fd2);
	write(fd2,"hello",5);
	close(1);
	dup(fd);
	printf("dup\n");
	dup2(fd,fd2);
	system("date");
	write(fd2,"dup2\n",5);
	write(fd,"fd\n",3);
//	printf("fd=%d\n",fd);
}
