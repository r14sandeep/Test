#include<stdio.h>
#include<string.h>
char *mystrchr(char *a,char ch)
{
	int i;
	for(i=0;a[i];i++)
	{
		if(a[i]==ch)
			return (a+i);
	}
	return 0;

}
char *mystrrchr(char *a,char ch)
{
	char *p=0;
	int i;
	for(i=0;a[i];i++)
	{
		if(a[i]==ch)
			p=a+i;

	}
	return p;

}
char *mystrchrnul(char *a,char ch)
{
	char *p=0;
	int i;
	for(i=0;a[i];i++)
	{
		if(a[i]==ch)
			return (a+i);

	}
	return (a+i);

}

main()
{
	char a[10],ch,*p;
	puts("enter a");
	gets(a);
	puts("enter char");
	scanf("%c",&ch);
	//p=mystrchr(a,ch);
	//p=mystrrchr(a,ch);
	p=mystrchrnul(a,ch);
	printf("%u\n",a);
	printf("%u\n",p);
}

