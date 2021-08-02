#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
float myatof(char *);
main()
{
	char a[10];
	float b;
	puts("enter string");
	gets(a);
	b=myatof(a);
//	printf("%d\n",b);
	printf("%f\n",b);

}
float myatof(char *p)
{
	float a,b=0;
	int cnt=0;
	float c=0;
	while(*p)
	{
		a=(*p)-48;
		b=(b*10)+a;
	p++;
	if(*p=='.')
		break;
	}
	p++;
	while(*p)
	{
		a=(*p)-48;
		c=(c*10)+a;
		p++;
		cnt++;
	}
	c=c*(pow(10,-cnt));
	b=b+c;
	return b;
}
