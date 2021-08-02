#include<stdio.h>
/*main()
{
	int i,j,n;
	printf("enter n value:");
	scanf("%d",&n);
for(j=1;j<=(n+1);j++)
{
	printf("* ");
}
printf("\n");
for(i=1;i<=n;i++,printf("\n"))
{
	for(j=1;j<=(2*i-1);j++)
		printf(" ");
	for(j=1;j<=(n-i+1);j++)
		printf(" *")     ;
}
for(i=1;i<=(n-1);i++,printf("\n"))
{
	for(j=1;j<=(n-i);j++)
		printf("  ");//2 spaces
	for(j=1;j<=(i+1);j++)
		printf("* ");
}
for(j=1;j<=(n+1);j++)
{
	printf("* ");
}
printf("\n");
}*/
/***********          *************/
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
	for(j=0;j<=(n+1);j++)
		printf("%c",(j<(n-k))?' ' :'*');

}
}
