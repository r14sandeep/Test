#include"header.h"
int main(int argrc,char **argv)
{
	int fd;
	char data[20],ch;
	fd=open(argv[1],O_RDONLY);
	while(read(fd,data,20))
	{
		puts(data);
		//printf("%c",ch);
	}
	close(fd);
}
