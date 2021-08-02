//febnocci series
#include<stdio.h>
main()
{
	int a=0,b=1,max,c;
	printf("enter max");
	scanf("%d",&max);
if(max==0)
{	printf("feb series is 0");
	return 0;
}
	printf("feb series is %d,%d",a,b);
while((c=a+b)<=max)
{	a=b;
	b=c;
printf(",%d",c);
}
printf("\n");

}

