#include<stdio.h>
main()
{
	char a[20],b[20];
	int i;
	puts("enter a,b");
	gets(a);
	gets(b);
	i=strcmp(a,b);
	printf("%d\n",i);

}
