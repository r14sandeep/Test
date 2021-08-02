#include<stdio.h>
#include<stdarg.h>
int sum(int,...);
main()
{
	int a=100,b=200;
	printf("%d\n",sum(6,1,2,3,0,4,5));// here 6 is the count of no.of ints
	printf("%d\n",sum(4,11,22,0,33));
	printf("%d\n",sum(3,a,0,b));

}
int sum(int cnt,...)
{
	int s=0;
	va_list handle;
	va_start(handle,cnt);
	while(cnt--)
		s+=va_arg(handle,int);
	va_end(handle);
	return s;

}
