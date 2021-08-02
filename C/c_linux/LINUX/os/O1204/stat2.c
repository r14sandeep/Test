#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
main(int argc,char **argv)
{
	struct stat v;
	if(lstat(argv[1],&v)==-1)
	{
		perror("stat");
		exit(0);
	}
	printf("size:%u hlinks:%d\n",(unsigned int)v.st_size,(int)v.st_nlink);
	printf("mode:%o\n",(unsigned int)v.st_mode);
	printf("gid:%u\n",(unsigned int)v.st_gid);
	printf("blocks:%d\n",(int)v.st_blocks);
//	printf("atime:%d\n",(int)v.st_atime);

//	printf("mtime:%d\n",(int)v.st_mtime);

}
