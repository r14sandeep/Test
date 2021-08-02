#include"header.h"
main()
{
	int p[2],cnt=0;
	pipe(p);
	while(1)
	{
		if(write(p[1],"a",1)==1)
			cnt++;
		else 
			break;
	printf("size=%d\n",cnt);
	}
}
