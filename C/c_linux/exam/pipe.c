/////wap to input a file in cmd line and a string in parent,search that string  in child and print the occurance in parent

#include"header.h"
main(int argc,char **argv)
{
	int fd,size,cnt=0,p[2];
	char *buf,*found,str[10];
	pipe(p);
	fd=open(argv[1],O_RDONLY);
	size=lseek(fd,0,2);
	lseek(fd,0,0);
	buf=calloc(1,size+1);
	read(fd,buf,size+1);
	found=buf;
	if(fork()==0)
	{
		printf("%s",buf);
		read(p[0],str,strlen(str)+1);
		while(found=strstr(found,str))
		{
			cnt++;
                        found++;
		}
		printf("%d\n",cnt);
		write(p[1],&cnt,4);
	}
	else
	{
		printf("enter string:");
		gets(str);
		write(p[1],str,strlen(str)+1);
		sleep(1);
		read(p[0],&cnt,4);
		printf("%d\n",cnt);
	}

}
