#include"header.h"
main()
{
	int cnt=0,p[2];
	pipe(p);
	while(1)
	{
		write(p[1],"a",1);
			cnt++;
	printf("size=%d\n",cnt);

	}
//	printf("size=%d\n",cnt);

}

