#include"header.h"
int main()
{
	int p[2];
	char buf[10],rd[10];
	pipe(p);
	int cnt=0;
	while(1)
	{
		if(fork())
		{
			puts("enter msg:");
			write(p[1],buf,strlen(buf));
		}
		else
		{
			if(cnt>5)
			{	read(p[0],rd[10],10);
				puts(rd);
			}	
	cnt++;
				
		}

	}

}
