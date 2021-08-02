#include<stdio.h>
#include<string.h>
main()
{
	char a[10],b[10],*p;
	puts("enter a,b");
	gets(a);
	gets(b);
	p=strpbrk(a,b);
	if(p==0)
		return;
	puts(p);
	


}
