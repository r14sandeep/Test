#include<stdio.h>
main()
{
int i,j,a;
printf("enter data");
scanf("%d",&a);
//printf("%d",sizeof(int));
for(i=0;i<=31;i++)
{	
	printf("%d",(a>>i)&1);	
}
printf("\n");
for(i=31,j=0;i>j;i--,j++)
{
	if(((a>>i)&1)!=((a>>j)&1))
	{
		a^=(1<<i);
		a^=(1<<j);
	}
//printf("%d",a);
}
printf("%d\n",a);
}
