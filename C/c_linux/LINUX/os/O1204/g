#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
main(int argc,char **argv)
{
	DIR *dp;
	struct dirent *ptr;
	dp=opendir(argv[1]);
	while(ptr=readdir(dp))
		//printf("%s %d \n",ptr->d_name,ptr->d_ino);
		printf("%s %d type:::::%c\n",ptr->d_name,ptr->d_ino,(unsigned char)ptr->d_type);
	closedir(dp);

}
