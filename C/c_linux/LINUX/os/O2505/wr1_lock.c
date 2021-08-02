#include"header.h"
int main()
{
	struct flock v;
	char str[20]="abcdefgh";
	int fd,i;
	fd=open("datafile",O_CREAT|O_WRONLY|O_APPEND,0666);
	printf("enter to write:");
	getchar();

//////////////critical region///////////
	v.l_type=F_WRLCK;
	v.l_whence=0;
	v.l_start=0;
	v.l_len=0;
	fcntl(fd,F_SETLKW,&v);///F_SETLKW will lock the file if not locked,if locked it will wait untill unlock

	for(i=0;str[i];i++)
	{
		write(fd,str+i,1);
		puts("wr1 is writing");
		sleep(1);
	}
///////////////////////////////////

	puts("writingdone");
	close(fd);

}
