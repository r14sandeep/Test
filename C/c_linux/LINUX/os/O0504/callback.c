#include<stdio.h>
int sum(int x,int y)
{
	return x+y;
}
int mul(int x,int y)
{
	return x*y;
}
int f(int i,int j,int (*p)(int,int))
{
	return ((*p)(i,j));
}
main()
{
	int a=11,b=22,c;
	printf("enter 1:sum 2:mul\n");
	scanf("%d",&c);
	if(c==1)
		printf("result %d\n",f(a,b,sum));
	else
		printf("mul %d\n",f(a,b,mul));
}
