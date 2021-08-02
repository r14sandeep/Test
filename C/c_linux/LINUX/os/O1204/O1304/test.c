#include<stdio.h>
#include<unistd.h>
main()
{
	write(1,"hello",5);
	close(1);
	write(1,"india",6);
}
