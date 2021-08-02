#include"header.h"
int main(int argrc,char **argv)
{
	int fd;
	char data[20];
	fd=open(argv[1],O_WRONLY|O_CREAT);
	puts("enter data to file:");
	gets(data);
	while(strcmp(data,"quit")!=0)
	{
		write(fd,data,strlen(data));
		puts("enter data to file:");
		gets(data);
	}
	close(fd);
}
