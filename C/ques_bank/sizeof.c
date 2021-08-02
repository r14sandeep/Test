#include<stdio.h>
int main()
{
	double a,b;
	int c;
	c=(int)&b-(int)&a;
	printf("a=%u\n",&a);
	printf("b=%u\n",&b);
	printf("size=%d\n",c);
}
