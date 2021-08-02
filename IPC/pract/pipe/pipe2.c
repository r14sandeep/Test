#include<stdio.h>
int main()
{
	int p[2];
	pipe(p);
	if(fork()==0)
	{
		int x=1;
		for(x=1;x<=10;x++)
		{
			puts("writing");
			sleep(1);
			write(p[1],&x,4);
		}

	}
	else
	{
		int y;
		sleep(10);
		do{
			read(p[0],&y,4);
			printf("%d\n",y);
			sleep(1);
		}while(y!=10);

	}


}
