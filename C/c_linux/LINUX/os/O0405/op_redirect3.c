#include"header.h"
main()
{
	int fd1,a,b;
//	fd1=open("f1",O_RDONLY);
	fd1=open("f1",O_WRONLY);
	close(1);
	dup(fd1);
	printf("enter a,b:");
	scanf("%d%d",&a,&b);
	printf("%d\n",a+b);
//	execlp("cal","cal",0);
	close(fd1);

}
