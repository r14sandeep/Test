#include<stdio.h>
#include<stdarg.h>
void print(char *ptr,...)
{
	va_list handle;
	puts(ptr);
	va_start(handle,ptr);
	while(ptr=va_arg(handle,char *))
		puts(ptr);
	va_end(handle);

}
int main()
{
	char *p1="abc",*p2="xyz",s1[]="aaa",s2[]="bbb";
	print("111","123","345",NULL);
	print("hello",NULL);
	print(p1,p2,s1,s2,NULL);
}
