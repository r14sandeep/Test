#include<stdio.h>
int prime(int n)
{
	int i=2;
	while(i<=n/2)
	{
		if(n%i==0)
			return 1;
		i++;
	}
	return 0;

}
void print(int num,int(*ptr)(int))
{
	int i;
	i=ptr(num);
	if(i==0)
		puts("prime number");
	else
		puts("not a prime");
	

}
int main()
{
	int num;
	printf("enter a num:");
	scanf("%d",&num);
	
	print(num,prime);


}
