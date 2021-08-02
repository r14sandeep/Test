#include<fcntl.h>
#include<stdio.h>
main(int argc,char **argv)
{
	int fd;
	char ch;
	fd=open(argv[1],O_WRONLY);
	if(fd==-1)
	{
		perror("open");
		return;
	}
	printf("fd=%d\n",fd);
	while(read(fd,&ch,1)==1)
		printf("%c",ch);
	close(fd);
}	
