#include"header.h"
main()
{
	int fd1,fd2;
	char v;
	fd1=open("f1",O_RDWR);
	printf("fd1=%d\n",fd1);
	read(fd1,&v,1);
	fd2=fcntl(fd1,F_DUPFD,0);
	printf("fd2=%d\n",fd2);
	read(fd2,&v,1);
	printf("%c\n",v);
	lseek(fd2,1,1);
	read(fd1,&v,1);
	printf("%c\n",v);
	close(fd1);
	close(fd2);
}
