#include<stdio.h>
int sum(int,int);
int mul(int,int);

main()
{
	int v1,v2,r;
	printf("enter v1,v2");
	scanf("%d%d",&v1,&v2);
	r=sum(v1,v2);
	printf("sum=%d\n",r);
	r=mul(v1,v2);
	printf("mul=%d\n",r);
	


}
