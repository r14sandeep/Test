#include<stdio.h>
#include<string.h>
main()
{
	char a[10],b[10];
	int n,p;
	puts("enter a,b");
	gets(a);
	gets(b);
	printf("enter pos:");
	scanf("%d",&p);
	n=strlen(b);
	memmove(a+n,a+p,strlen(a+p)+1);
	memmove(a+p,b,strlen(b));
	puts(a);
}
