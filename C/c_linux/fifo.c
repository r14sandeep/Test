#include"header.h"
main(int argc,char **argv)
{
	int fd,fd1,size;
	char *buf;
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifo");
	if(mkfifo("fifo1",0660)==-1)
		perror("mkfifo1");
	fd=open(argv[1],O_RDONLY);
	size=lseek(fd,0,2);
	lseek(fd,0,0);
	printf("%d\n",size);
	buf=calloc(1,size+1);
	read(fd,buf,size);
	close(fd);
	fd=open("fifo",O_WRONLY);
	fd1=open("fifo1",O_WRONLY);

	write(fd,buf,size+1);
	//printf("%d\n",size);
	write(fd1,(char *)size,4);
//	printf("%d\n",size);
	close(fd);
	close(fd1);

}
