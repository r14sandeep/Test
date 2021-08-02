#include<stdio.h>
main()
{
	int i,n,j;
	printf("enter n:");
	scanf("%d",&n);
	for(i=1;i<=n+1;i++,printf("\n"))
		for(j=1;j<=n+1;j++)
		(j<=(n-i+1))?printf("  "):printf("* ");
	


}
