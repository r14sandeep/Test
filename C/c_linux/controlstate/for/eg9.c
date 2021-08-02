//prog to calculate fact of given int
#include<stdio.h>
main()
{
	int i,a,r=1;
loop:	printf("enter a value");
	scanf("%d",&a);
if(a<0)
{	printf("invalid data,i/p again\n");
	goto loop;
}
if(a==0)
{	printf("fact of a is 1\n");
	return 0;}
for(i=1;i<=a;i++)
	r=r*i;
printf("fact of a is %d\n",r);
}
