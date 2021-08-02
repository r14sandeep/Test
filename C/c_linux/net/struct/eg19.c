#include<stdio.h>
main()
{
	int a[3]={10,20,30},x=0;
	x=++a[++x]+ ++x +a[x--];
	printf("%d\n",x);


}
