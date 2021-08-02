#include"header.h"
main(int argc,char **argv)
{
	int sfd,tfd;
	int size;
	char *buf;
	sfd=open(argv[1],O_RDONLY);
	if(sfd==-1)
	{
		printf("error");return;
	}
	tfd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0600);
	size=lseek(sfd,0,2);
	buf=calloc(1,size);
	lseek(sfd,0,0);
	read(sfd,buf,size);
	write(tfd,buf,size);
	close(sfd);
	close(tfd);
}
