#include<stdio.h>
main()
{
	short n[3][2]={3,6,9,12,15,18};
	printf("%d %d\n",*(n+1)[1],**(n+2));
}
