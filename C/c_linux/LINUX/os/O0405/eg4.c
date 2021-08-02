#include"header.h"
main(int argc,char **argv)
{
	int sfd,tfd;
	char ch;
	sfd=open(argv[1],O_RDONLY);
	if(sfd==-1)
	{
		printf("error");return;
	}
	tfd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0600);	
	while(read(sfd,&ch,1)==1)
		write(tfd,&ch,1);
	close(sfd);
	close(tfd);
//	size=lseek();
}

