#include"header.h"
int main()
{
	int p[2];
	int v=2;
	if(pipe(p)==-1)
	{
		perror("pipe");
		return;

	}
	if(fork())
	{
		v+=2;
		printf("if:%d\n",v);
		sleep(8);
		write(p[1],&v,4);
	}	
	else{
		sleep(2);
		printf("else:%d\n",v);
		read(p[0],&v,4);
		printf("else:%d\n",v);
			
	}
}
