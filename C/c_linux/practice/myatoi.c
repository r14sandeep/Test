#include<stdio.h>
int myatoi(char p[])
{
	int i,temp=0;
	for(i=0;p[i];i++)
	{
		temp=temp*10+p[i]-48;
		
	}
	return temp;

}

main()
{
	char a[10];
	int i;
	puts("enter a");
	gets(a);
	
	i=myatoi(a);
	printf("%d\n",i);
}

