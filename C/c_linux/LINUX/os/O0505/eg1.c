#include"header.h"
int v=1;;
main()
{
	int p[2];
	pipe(p);
	if(fork())
	{
		v+=10;
		printf("%d\n",v);
	}
	else
	{
		sleep(5);
		printf("v=%d",v);	
	}


}
