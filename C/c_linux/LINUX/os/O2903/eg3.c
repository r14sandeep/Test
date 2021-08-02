#include<stdio.h>
#include<stdarg.h>
void print(char *,...);
main()
{
	char *p1="abc";
	char *p2="xyz";
	char s1[]="aaa";
	char s2[]="bbb";
	print("111","22","33",NULL);
	print("vector",NULL);
	print(p1,p2,s1,s2,NULL);
}
void print(char *ptr,...)
{
	va_list handle;
	puts(ptr);
	va_start(handle,ptr);
	while(ptr=va_arg(handle,char *))
		puts(ptr);
	va_end(handle);
}
