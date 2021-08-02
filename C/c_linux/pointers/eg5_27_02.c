#include<stdio.h>
#include<string.h>
int cnt=0;
const int MAX=20;
char **input(char **);
void print(char **);
void sort(char (*)[]);
main()
{
	char **buf=0,ch;
	while(1)
	{
	printf("i-input\np-print\nd-delete\ns-sort\nq-quit\n");
	printf("enter ur choice\n");
	scanf("%c",&ch);
	
	switch(ch)
	{
		case 'i':buf=input(buf);break;
		case 'p':print(buf);break;
		//case 'd':delete(name);break;
		case 's':sort(buf);break;
		case 'q':return;
		default:printf("invalid option\n");break;

	
	}}
}
char **input(char **p)
{
	p=(char **)realloc(p,(cnt+1)*sizeof(char *));
	p[cnt]=(char *)malloc(100);
	puts("enter a name");
	getchar();
	gets(p[cnt]);
	p[cnt]=realloc(p[cnt],strlen(p[cnt])+1);
	cnt++;
	return p;
}
void print(char **p)
{
	int i;
	for(i=0;i<cnt;i++)
		printf("name[%d]=%s\n",i,p[i]);
	
}
void sort(char **p)
{
	char temp[1][20];
	int i,j;
	for(i=cnt-1;i>=0;i--)
		for(j=0;j<i;j++)
			if(p[j][0]>p[j+1][0])
			{
				strcpy(temp,p[j+1]);
				strcpy(p[j+1],p[j]);
				strcpy(p[j],temp);

			}
	
	for(i=0;i<cnt;i++)
		printf("name[%d]=%s\n",i,p[i]);


}
