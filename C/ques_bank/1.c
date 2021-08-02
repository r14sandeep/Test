#include<stdio.h>
int main()
{
	int n;
	scanf("%x",&n);
	printf("%x\n",n);
	int rem,cnt=0;
	while(n)
	{
		rem=n%16;
		cnt++;
		n=n/16;
	}
	printf("%d\n",cnt);
}
