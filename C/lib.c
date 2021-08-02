#include<stdio.h>
int sum(int,int);
int mul(int,int);
int main()
{
	int v1,v2;
	printf("enter v1,v2:");
	scanf("%d%d",&v1,&v2);
	int r;
	printf("sum=%d\n",sum(v1,v2));
	printf("mul=%d\n",mul(v1,v2));

}
