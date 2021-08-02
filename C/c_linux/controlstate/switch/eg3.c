#include<stdio.h>
main()
{
	char a[10];
	int i;
	printf("enter a:");
	scanf("%s",a);
	i=myatoi(a);	
	printf("%d\n",i);
}
int myatoi(char *a)
{
	int i,j=0;
	while(*a)	
	{
		i=(*a)-48;
		j=j*10+i;
		a++;
	}
	return j;

}
