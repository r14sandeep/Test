#include<stdio.h>
main()
{
	int i=1,j=1,digitcnt=0;
	int min,max;
	printf("enter min,max:");
	scanf("%d%d",&min,&max);
	i=max;
while(i)
{
	digitcnt++;
	i=i/10;}
	//printf("enter digitcnt:");
	//scanf("%d",&digitcnt);
	i=min;
while(i<=max)
{printf("%d ",i);
	j=1;
	while(j<=10)
	{
		printf("%*d",digitcnt+3,i*j);
		j++;
	}
	printf("\n");
	i++;}


}
