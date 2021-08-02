#include<stdio.h>
#include<string.h>
main()
{
	char a[10],b[10];
	int i;
	puts("enter a,b");
	gets(a);
	gets(b);
	i=bcmp(a,b,3);
	printf("%d\n",i);

}
