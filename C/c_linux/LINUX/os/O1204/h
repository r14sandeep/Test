#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
main(int argc,char **argv)
{
	struct stat v;
	if(stat(argv[1],&v)==-1)
	{
		perror("stat");
		exit(0);
	}
	//printf("size:%u hlinks:%d\n",(unsigned int)v.st_size,(int)v.st_nlink);
	printf("mode:%o\n",(unsigned int)v.st_mode);
	//if(v.st_mode>>8&1)
	if(v.st_mode&S_IRUSR)
		printf("r");
	else printf("-");
	if(v.st_mode>>7&1)
		printf("w");
	else printf("-");
	if(v.st_mode>>6&1)
		printf("x");
	else printf("-");
	printf("\n");	

}
