#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
main(int argc,char **argv)
{
	int fd;
	char str[100];
	fd=open(argv[1],O_WRONLY|O_APPEND);
	if(fd==-1)
		exit(0);
	while(1)
	{
		printf("write msg to file:(quit to stop):");
		scanf("%s",str);
		write(fd,str,strlen(str));
		if(strstr(str,"quit"))
			break;
		//	return;
	}
	close(fd);
}
