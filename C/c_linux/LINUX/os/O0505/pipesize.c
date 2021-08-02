#include"header.h"
main()
{
	int p[2],cnt=0,i;
	pipe(p);
		int x=1;
		for(x=1;;x++)
		{
			cnt++;
			write(p[1],&x,4);
		printf("%d\n",cnt);
		}
//		printf("%d\n",cnt-1);
		

}
