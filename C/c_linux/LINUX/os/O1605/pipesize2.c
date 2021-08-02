#include"header.h"
main()
{
	int cnt=0,p[2];
	pipe(p);
	fcntl(p[1],F_SETFL,O_NONBLOCK);
	while(1)
	{
		if(write(p[1],"a",1)==1)
			cnt++;
		//else break;
	printf("size=%d\n",cnt);
	}

}

