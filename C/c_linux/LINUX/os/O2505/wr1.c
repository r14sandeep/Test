#include"header.h"
main()
{
	struct flock v;

	char str[20]="12345678";
	int fd,i;
	fd=open("datafile",O_CREAT|O_WRONLY|O_APPEND,0666);
	printf("enter to write:");
	getchar();

/*	v.l_type=F_WRLCK;
	v.l_whence=0;

	v.l_start=0;
	v.l_len=0;
	fcntl(fd,F_SETLKW,&v);
*/
	for(i=0;str[i];i++)
	{
		write(fd,str+i,1);
		puts("wr1 is writing");
		sleep(1);
	}

	puts("writingdone");

}
