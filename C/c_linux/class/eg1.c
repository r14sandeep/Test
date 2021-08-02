#include<stdio.h>
main()
{
	int i,j,k,n;
	printf("enter n:");
	scanf("%d",&n);
	for(i=-n;i<=n;i++,printf("\n"))
	{
		k=-i;
		if(k<0)
			k=-k;
		for(j=0;j<=n+2;j++)
		((n+1-k)>(n-k))?printf("* "):printf("  ");

	}
	



}
