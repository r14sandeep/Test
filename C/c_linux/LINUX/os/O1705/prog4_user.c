#include"header.h"
void client(char *cmd)
{
	int fd1,fd2;
	char rdbuf[200],a[200];
	if(mkfifo("fifo",0660)==-1)
		perror("mkfile");
	fd1=open("fifo1",O_RDWR);
	write(fd1,cmd,strlen(cmd)+1);
//	printf("%s\n",cmd);
	fd2=open("fifo2",O_RDWR);
	read(fd2,rdbuf,200);
//	system(rdbuf);
	printf("%s ",rdbuf);
//	gets(rdbuf);
}


main()
{
	char cmd[10];
	puts("enter cmd");
	gets(cmd);
	client(cmd);	


}
