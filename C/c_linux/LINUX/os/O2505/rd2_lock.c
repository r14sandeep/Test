#include"header.h"
main()
{
	struct flock v;
	char str[20]="12345678",ch;
	int fd,i;
	fd=open("datafile",O_RDONLY,0666);
	printf("enter to read:");
	getchar();
//////////////////////
	v.l_type=F_RDLCK;
	v.l_whence=0;
	v.l_start=0;
	v.l_len=0;
	fcntl(fd,F_SETLK,&v);

//	for(i=0;;i++)
//	{
//		if(read(fd,str+i,1)==-1)
//			break;
		while(read(fd,&ch,1))
		{
			if(ch==EOF)
				break;
			printf("rd2 %c\n",ch);
			sleep(1);
		}
//	}
	
	puts("readingdone");
	close(fd);

}
