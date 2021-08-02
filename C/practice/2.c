#include<stdio.h>
int main()
{
	int a=2,b=4,*p;
	p=&a;
	p++;
//	b=(&a+1)-&a;
	b=((int)p-(int)(&a));
	printf("%d,%d\n",&a,b);
	printf("%d %d\n",p,&a);

}
