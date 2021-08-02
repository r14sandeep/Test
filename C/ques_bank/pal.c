#include<stdio.h>
int len=0;
char temp[20];
void pal(char *str)
{
	int i,j,n;
	n=strlen(str);
	for(i=0,j=n-1;i<j;i++,--j)
		if(str[i]==str[j])
			continue;
		else
			break;
	if((i==j)||(i>j))
	{
		if(len<n)
		{
			len=n;
			strcpy(temp,str);
		}
	}
}
int main()
{
	FILE *fp;
	fp=fopen("test.txt","r");
	char line[100],string[20];
	while(fscanf(fp,"%s",string)!=EOF)
	{
//		puts(string);
		pal(string);
		
	}
	puts(temp);
}
