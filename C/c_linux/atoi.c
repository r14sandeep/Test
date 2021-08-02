#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[10];
	long int b;
	puts("enter string");
	gets(a);
	b=myatoi(a);
	printf("%d\n",b);
//	printf("%lli\n",atoq(a));
}
int myatoi(char *p)
{
	int a,b=0;
	while(*p)
	{
		a=(*p)-48;
		b=(b*10)+a;
	p++;
	}
	return b;
}
