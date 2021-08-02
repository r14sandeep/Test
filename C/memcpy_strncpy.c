#include<stdio.h>
int main()
{
	char str[10]="123456\0abcdefghij";
	char str2[20];
//	puts(str);
//	char *str2;
//	gets(str);
	memcpy(str2,str,18);
//	strncpy(str2,str,15);
	int i;
	for(i=0;i<20;i++)
		printf("%c ",str2[i]);
	printf("\n");
//	puts(str2);

}
