#include<stdio.h>
#include<string.h>
char *mystrpbrk(char *a,char *b)
{
	int i,j;
	for(i=0;b[i];i++)
		for(j=0;a[j];j++)
			if(b[i]==a[j])
				return (a+j);
	return 0;
}
main()
{
	char a[10],b[10],*p;
	puts("enter a,b");
	gets(a);
	gets(b);
	p=mystrpbrk(a,b);
	if(p==0)
		printf("0\n");
	else
	puts(p);

}

