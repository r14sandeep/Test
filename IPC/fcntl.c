#include"header.h"
int main(int argc,char **argv)
{
	char v;
	int fd1,fd2;
	fd1=open(argv[1],O_RDWR|O_APPEND);
	close(1);
	fd2=fcntl(fd1,F_DUPFD,0);
//	dup(fd1);
	printf("fd1=%d\n",fd1);
	printf("enter to exit\n");
	scanf("%c",&v);
	close(fd1);
	close(fd2);


}
