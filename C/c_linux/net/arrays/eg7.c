#include<stdio.h>
main()
{
	static int a=2,b=4,c=8;
	static int *a1[2]={&a,&b};
	static int *a2[2]={&b,&c};
	int *(*d[2])[2]={&a1,&a2};
	printf("%d %d\n",*(*d[0])[1],*(*(**(d+1)+1)));
	


}
