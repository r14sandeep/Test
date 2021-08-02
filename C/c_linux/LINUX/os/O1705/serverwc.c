#include"header.h"
main()
{
	int fd,fd1;
	char rdbuf[200],wrbuf[10],str[20];
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifo");
/*	if(fork())
	{
	fd=open("fifo",O_RDONLY);
	printf("waitning for fifo\n");
	close(0);
	dup(fd);
	execlp("wc","wc",NULL);
//	read(fd,rdbuf,200);
//	system(rdbuf);
	}
	else
	{
	fd1=open("fifo",O_WRONLY);
	close(1);
	dup(fd1);
	execlp("ls","ls",NULL);
	//write(fd1,str,20);
	}
*/
	fd=open("fifo",O_RDONLY);
	read(fd,rdbuf,200);
	puts(rdbuf);
//	close(0);
//	dup(fd);
//	execlp("wc","wc",NULL);
	//system("wc rdbuf");

}	
