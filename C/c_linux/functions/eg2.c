//highest of a no
#include<stdio.h>

int findmax(int v)
{
	int temp=-1;
while(v)
{
	if(v%10>temp)
		temp=v%10;
	v=v/10;
}
return temp;
}
main()
{
	int v;
	printf("enter a number:");
	scanf("%d",&v);
//	findmax(v);
//	v=findmax(v);
	printf("highest digit is:%d\n",findmax(v));
}





