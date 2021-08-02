#include<stdio.h>
main()
{
	int i,j,n;
	printf("enter n value:");
	scanf("%d",&n);
for(i=1;i<=n;i++,printf("\n"))
{
	for(j=1;j<=i;j++)
		printf(" ");
	for(j=1;j<=(n-i+1);j++)
		printf(" *");
}
for(i=2;i<=n;i++,printf("\n"))
{
	for(j=1;j<=(n-i+1);j++)
		printf(" ");
	for(j=1;j<=i;j++)
		printf(" *");
}
//for(j=1;j<=(n-1);j++)
//	printf("* ");
printf("\n");

}
