#include<stdio.h>
int main()
{
	int num,res=1;
	printf("enter a num:");
	scanf("%d",&num);
	while(num)
	{
		res*=num;
		num--;
	}

	printf("fact=%d\n",res);
}
