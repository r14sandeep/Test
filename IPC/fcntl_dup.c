#include"header.h"
int main(int argc,char **argv)
{
	int fd1,fd2;
	char v;
	fd1=open(argv[1],O_RDONLY);
	printf("fd1=%d\n",fd1);
	read(fd1,&v,1);
	printf("%c\n",v);
	fd2=fcntl(fd1,F_DUPFD,0);
	printf("fd2=%d\n",fd2);
	read(fd2,&v,1);
	printf("%c\n",v);
	read(fd1,&v,1);
	printf("%c\n",v);
	
return 0;
}
