//to print a power b,wheen a,b are i/ps
#include<stdio.h>
main()
{
	int a,b,i,r=1;
loop:	printf("enter a,b");
	scanf("%d%d",&a,&b);
	if(b<0)
	{	printf("invalid data,i/p again");		
		goto loop;}
for(i=1;i<=b;i++)
	r=r*a;

printf("%d\n",r);


}
