#include"header.h"
main()
{
	char str[20]="abcdefgh";
	int fd,i;
	fd=open("datafile",O_CREAT|O_WRONLY|O_APPEND,0666);
	printf("enter to write:");
	getchar();
	for(i=0;str[i];i++)
	{
		write(fd,str+i,1);
		puts("wr2 is writing");
		sleep(1);
	}
	puts("writingdone");

}
