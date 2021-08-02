#include<stdio.h>
main()
{
	int i,j,n;
	printf("enter n val:");	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	for(j=i;j<n;j++)
			printf("* ");
		printf("\n");
	}	

}
