#include"header.h"
int main()
{
	int cnt=1,p[2];
	pipe(p);
	fcntl(p[1],F_SETFL,O_NONBLOCK);
	while(cnt)
	{
		write(p[1],&cnt,4);
		printf("%d\n",cnt);
		cnt++;
	}
}
