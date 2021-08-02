#include<stdio.h>
int main()
{
	char str[10],st[10];
	char *s;
	int c,d;
	char ch;
	gets(str);
//	puts(str);
	s=str;
	int cnt=0;
	sscanf(str,"%s",st);

	puts(st);
/*	sscanf(s,"%d%c%d",,&c,&ch,&d);
	printf("%c\n",ch);
	printf("%d\n",d);
	printf("sum:%d\n",c+d);
*/
}
