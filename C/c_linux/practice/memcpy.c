#include<stdio.h>
#include<string.h>
main()
{
	char a[10],b[10];
	puts("enter a");
	gets(a);
	memcpy(b,a,2);
	puts(b);

}
