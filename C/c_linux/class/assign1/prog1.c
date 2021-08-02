//program to count the no.of odd digits in given int
#include<stdio.h>
main()
{
	int v,count=0,temp,a;
	printf("enter an int:");
	scanf("%d",&v);
	temp=v;
loop:
	a=temp%10;
	temp=temp/10;
	if(a%2==1)
	  count++;
	if(temp)
	  goto loop;
	printf("%d\n",count);

}
