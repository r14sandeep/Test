#include<stdio.h>
main()
{
	int i,j,n;
	printf("enter n value:");
	scanf("%d",&n);
for(i=1;i<=n;i++,printf("\n"))
{
	if(i%2==0)
	{
		for(j=1;j<=i;j++)
		{
			if(j%2==1)
				printf("0 ");
			else
				printf("1 ");
	}}
	else{
		for(j=1;j<=i;j++)
		{
			if(j%2==1)
				printf("1 ");
			else
				printf("0 ");
		}
	}


}}
