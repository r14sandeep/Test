#include"header.h"
void f(int n)
{
printf("%d\n",n);

}
int main()
{
	char rdbuf[20];
	int fd;
	if(mkfifo("fifo",0660)==-1)
		perror("mkfifo");
	
	fd=open("fifo",O_RDWR);
	while(1)
	{
		puts("waiting for fifo read");
		bzero(rdbuf,20);
		read(fd,rdbuf,20);
		//puts(rdbuf);
		printf("msg is:%s\n",rdbuf);
	
	}
	signal(SIGPIPE,f);
	close(fd);
}
