#include<stdio.h>
int main()
{
	int num,l,r,index;
	printf("enter num:");
	scanf("%d",&num);
	printf("enter l,r:");
	scanf("%d%d",&l,&r);
	for(index=l-1;index<r;index++)
		num|=(1<<index);
	printf("after set:%d\n",num);


}
