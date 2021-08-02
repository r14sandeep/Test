#include<stdio.h>
main()
{
	write(1,"hello",5);
	close(1);
	write(1,"india",5);

}
