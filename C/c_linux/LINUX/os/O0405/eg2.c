#include"header.h"
main()
{
	int fd;
	char ch;
	fd=open("f1",O_RDWR);
//	read(fd,&ch,1);
//	printf("%c\n",ch);
	write(fd,"x",1);
	close(fd);

}
