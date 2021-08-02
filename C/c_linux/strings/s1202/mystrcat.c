#include<stdio.h>
#include<string.h>
char *mystrcat(char *,char *);
main()
{
	char a[10],b[10],*p;
	int i,n,j;
	puts("enter a:");	
	gets(a);
	puts("enter b:");	
	gets(b);
/*	printf("strcat(a,b)\n");
	n=strlen(a);
	
	//j=sizeof(b)/sizeof(b[0]);
	j=strlen(b);
	printf("n=%d,j=%d\n",n,j);
	for(i=0;i<j;i++)	
	{
		a[n++]=b[i];
	}*/
	p=mystrcat(a,b);
	puts(p);
}
char *mystrcat(char *a,char *b)
{
	int i,j,n;
	n=strlen(a);
	printf("n=%d\n",n);
	//j=sizeof(b)/sizeof(b[0]);
	j=strlen(b);
	printf("j=%d\n",j);
	for(i=0;b[i];i++)	
	{
		a[n]=b[i];
		n++;
		
	}
	a[n]='\0';
	puts(a);
	return a;
}
