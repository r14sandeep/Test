#include"header.h"
main()
{
	int fd;
	fd=creat("f3",S_IRUSR|S_IWUSR);
	write(fd,"india",10);
	close(fd);

}
