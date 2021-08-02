#include<stdio.h>
#include<string.h>
main()
{
	char a[20]="abcde";
	char b[20]="123";
	memmove(a+1,a+2,strlen(a+2)+1);
	printf("a:%s\n",a);


}
