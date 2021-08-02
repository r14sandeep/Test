#include<stdio.h>
int prime(int num)
{
	int index1,index2;
	for(index2=2;index2<=num/2;index2++)
		if(num%index2==0)
			return 1;
	return 0;
}
int fib(int num)
{
	int v1=0,v2=1,sum=0;
	while(sum<num)
	{
		sum=v1+v2;
		v1=v2;
		v2=sum;
		if(sum==num)
		{
			printf("num %d is fibnoccci-prime\n",num);
			break;

		}
		if(sum>num)
		{
			printf("num %d is not fibnoccci-prime\n",num);
			break;

		}
	}

}
int main()
{
	int a=0,b=1,c,num,stat;
	printf("input:");
	scanf("%d",&num);
	
	stat=prime(num);	
	if(stat==1)
		printf("num %d is not fibnocci-prime\n",num);
	else
		fib(num);

}
