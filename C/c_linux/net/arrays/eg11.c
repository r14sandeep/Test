#include<stdio.h>
main()
{
	int a[]={10,20,30,40,50};
	int i=4,x=9;
	x=(1*a[--i])+(2*a[--i])+(3*a[--i])+(4*a[--i]);
	printf("%d %d\n",x,i);

}
