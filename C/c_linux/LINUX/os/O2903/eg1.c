#include<stdio.h>
void print(char *,...);
main()
{
	char *p1="abc";
	char *p2="xyz";
	char s1[]="aaa";
	char s2[]="bbb";
	print("111","22","33");
	print("vector");
	print(p1,p2,s1,s2);
}
void print(char *ptr,...)
{
	puts(ptr);

}
