#include<stdio.h>
/*main()
{
	int i,j,n;
	printf("enter n value:");
	scanf("%d",&n);
for(i=1;i<=n;i++,printf("\n"))
{
	for(j=1;j<=(n-i);j++)
		printf(" ");
	for(j=1;j<=i;j++)
		printf(" *");
}
for(j=1;j<=(n+1);j++)
{	
	printf("* ");
}
printf("\n");
for(i=1;i<=n;i++,printf("\n"))
{
	for(j=1;j<=i-1;j++)
		printf(" ");
	for(j=1;j<=(n-i+1);j++)
		printf(" *");
}


}*/
main()
{
	int i,j,n,k;
	printf("enter n value:");
	scanf("%d",&n);
for(i=-n;i<=n;i++,printf("\n"))
{
	k=i;
	if(k<0)
		k=-k;
	for(j=1;j<=(n+1);j++)
			(k>=j)?printf(" "):printf("* ");



}

}
