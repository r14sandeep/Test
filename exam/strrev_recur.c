#include<stdio.h>
void fun(char *ptr)
{
	static int n;
	char temp;
/*	if(ptr==NULL)
		return;
	else
	{
		fun(ptr+1);
		printf("%c",*ptr);
	}
*/
	if(*ptr)
	{
		fun(ptr+1);
		printf("%c",*ptr);
	}
//	printf("\n");return;
}
int main()
{
	char str[10];
	puts("enter a string:");
	gets(str);
	fun(str);
//	puts(str);
}
