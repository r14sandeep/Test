#include<math.h>
#include<stdio.h>
main()
{
	int a,i,limit;
	printf("enter a value");
	scanf("%d",&a);
	limit=sqrt(a);
for(i=2;i<=limit;i++)
{
	if(a%i==0)
		break;
}
if(i==(limit+1))
	printf("prime\n");
else printf("not a prime\n");



}
