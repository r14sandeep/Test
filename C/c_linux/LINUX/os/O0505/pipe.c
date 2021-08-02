#include"header.h"
int v=1;
main()
{
	int p[2];
	pipe(p);
	if(fork())
	{
		v+=10;
		printf("in parent\n");
		printf("v=%d",v);
		write(p[1],&v,4);
	}
	else
	{
		sleep(5);
		printf("in child\n");
		printf("v=%d",v);	
		read(p[0],&v,4);
		printf("v=%d",v);
	}


}
