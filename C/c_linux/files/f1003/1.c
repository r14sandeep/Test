#include<stdio.h>
int main()
{
	int i=2;
	char a[20];
	gets(a);
//	scanf("%[^\n]s",a);
//	puts(a);
/*	switch(i)
	{
		case 1:puts("1");
		case 2:puts("2");
		case 3:puts("3");
		case 4:puts("4");
		default:puts("d");

	}
*/
	char b[10];
	gets(b);
	if(strcmp(a,b)==0)
		puts(b);		
}
