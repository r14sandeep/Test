#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print(char **);
char **input(char **);
int cnt=0;
main()
{
	char **buf=0,ch;
	while(1)
	{
		printf("i-input\np-print\nd-delete\n");
		printf("enter your choice:");
		scanf("%c",&ch);
		switch(ch)
		{
			case 'i':buf=input(buf);break;
			case 'p':print(buf);break;
//			case 'd':buf=del(buf);break;
		}
	}
}
char **input(char **p)
{
	p=(char **)realloc(p,(cnt+1)*sizeof(char *));
	p[cnt]=(char *)malloc(100);
	puts("enter a name");
	getchar();
	gets(p[cnt]);
	p[cnt]=realloc(p[cnt],strlen(p[cnt]));
	cnt++;
	return p;
}
void print(char **p)
{
	int i;
	for(i=0;i<cnt;i++)
		printf("name[%d]=%s\n",i,p[i]);



}
