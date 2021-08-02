//prog to print the sum of digits of given no:
#include<stdio.h>
main()
{
	int v,sum=0,temp,a;
	printf("enter an int:");
	scanf("%d",&v);
	temp=v;
loop:	a=temp%10;
	temp=temp/10;
	sum=sum+a;
	if(temp)
		goto loop;
	printf("sum=%d\n",sum);



}
