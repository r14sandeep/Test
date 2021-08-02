#include<stdio.h>
#include<string.h>
main()
{
	char a[20],b[20];
	gets(a);
	strcpy(a+2," ");
	printf("%s\n",a);

}
