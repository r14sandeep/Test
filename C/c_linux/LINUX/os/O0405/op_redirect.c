#include"header.h"
main()
{
	char v;
	int fd1,fd2;
	fd1=open("f1",O_RDWR|O_APPEND);
	printf("fd1=%d in  %d\n",fd1,getpid());
	close(1);
	fd2=fcntl(fd1,F_DUPFD,1);
	printf("fd2=%d in  %d\n",fd2,getpid());
	printf("enter to exit\n");
	//scanf("%c",v);
	getchar();
	close(fd1);
	close(fd2);

}
