#include"header.h"
int main(int argc,char **argv)
{
	int sfd,tfd;
	sfd=open(argv[1],O_RDONLY);
	char *buf;
	int size;
	size=lseek(sfd,0,2);
	lseek(sfd,0,0);
	buf=calloc(1,size);
	read(sfd,buf,size);
	tfd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0600);
	write(tfd,buf,size);
	close(sfd);
	close(tfd);
	return 0;
}
