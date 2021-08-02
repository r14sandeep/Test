#include<stdio.h>
/*main()
{
	int i,j,n;
	printf("enter n value:");
	scanf("%d",&n);
for(i=1;i<=n;i++,printf("\n"))
{
	for(j=1;j<=(i-1);j++)
		printf(" ");
	for(j=1;j<=(n-i+1);j++)
		printf("* ");
}

}*/
main()
{
	int i,j,n;
	printf("enter n value:");
	scanf("%d",&n);
for(i=1;i<=n;i++,printf("\n"))
{
	for(j=n;j>=1;j--)
		(j>(n-i+1))?printf(" "):printf("* ");

}
} 
