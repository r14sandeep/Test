#include<stdio.h>
char *mystrchr(char *,char *);
main()
{
	char a[100],ch;
	char *p;
	puts("enter a string:");
	gets(a);
	printf("%u\n",&a[0]);
	puts("enter char");
	scanf("%c",&ch);
	p=mystrchr(a,ch);
	printf("%u\n",p);
}
char *mystrchr(char *p,char ch)
{	
	int i;
	for(i=0;p[i];i++)
	{	if(p[i]==ch)
			return (p+i);
	}
	return 0;
}
