#include<stdio.h>
main()
{
	printf("before close\n");
	sleep(1);
	close(1);
	printf("after close\n");
	

}
