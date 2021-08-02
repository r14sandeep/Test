#include<stdio.h>
#include<stdarg.h>
int sum(int,...);
main()
{
	int a=100,b=200;
	printf("%d\n",sum(1,2,3,0,4,5,6));
	printf("%d\n",sum(11,22,0,33));
	printf("%d\n",sum(a,0,b));

}
int sum(int v,...)
{
	int s=v;
	va_list handle;
	va_start(handle,v);
	while(v=va_arg(handle,int))
		s+=v;
	va_end(handle);
	return s;

}
