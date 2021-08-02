#include<stdio.h>
#include<unistd.h>
main()
{
	printf("befor close\n");
	sleep(1);
	close(1);
	printf("after close\n");
	

}
