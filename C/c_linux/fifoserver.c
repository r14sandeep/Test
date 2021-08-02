#include"header.h"
main(int argc,char **argv)
{
	int fd,fd1,size,i;
	char *buf;
//	fd=open(argv[1],O_RDONLY);
	fd1=open("fifo1",O_RDONLY);
	fd=open("fifo",O_RDWR);
	//printf("%d\n",fd1);
	read(fd1,(char *)size,4);
	printf("%d\n",fd1);
	printf("%d\n",size);
	buf=calloc(1,size+1);
	close(fd1);
	read(fd,buf,size);
	fd1=open(argv[1],O_WRONLY);
	for(i=0;i<size;i++)
	{
		buf[i]=buf[i]-32;
		printf("%c",buf[i]);
	}
	write(fd,buf,size+1);
	close(fd);
	close(fd1);

}
