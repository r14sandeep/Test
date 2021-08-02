#include"header.h"
main()
{
	int p[2];
	pipe(p);
	if(fork()==0)
	{
		int x=1;
		for(x=1;x<=10;x++)
		{
			sleep(1);
			
			write(p[1],&x,4);
		}
	}
	else
	{
		int y;
		//sleep(20);
		do
		{
			read(p[0],&y,4);
			printf("%d\n",y);
		//	usleep(10000);	
		}while(y!=10);
	}

}
