#include<stdio.h>
#include<string.h>
main()
{
	char s[100];
	int i,j;
	puts("'entere s");
	gets(s);
	j=strlen(s);
	for(i=j-1;i>=0;i--)
	{
	printf("s[%d]=%s",i,s[i]);

	}



}
