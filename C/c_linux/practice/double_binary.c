#include<stdio.h>
int main()
{
	long long *i;
	int j;
	double f;
	printf("enter f:");
	scanf("%lf",&f);
	//i=(int *)&f;
	printf("%u\n",&f);
	i=(long long *)&f;
	for(j=63;j>=0;j--)
	{	
		printf("%d",(*i>>j)&1);

	}
	puts("");
}
