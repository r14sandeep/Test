#include"header.h"
main()
{
	int fd1,fd2;
	char rdbuf[10];
	fd1=open("fifo",O_RDWR);
	printf("wating for client\n");
	read(fd1,rdbuf,10);
//	system(rdbuf);
//	printf("%s\n",rdbuf);
	if(mkfifo("fifo2",0660)==-1)
		perror("mkfifo");
	fd2=open("fifo2",O_RDWR);
//	write(fd2,rdbuf,strlen(dbuf)+1);
//	printf("info about cmd has been sent to client\n");
	close(1);
	dup(fd2);
	//execlp("rdbuf","rdbuf",NULL);
	system(rdbuf);
	close(fd1);
	close(fd2);

}
