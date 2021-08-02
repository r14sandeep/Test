#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char str[10],**temp;
	gets(str);
	int n,i,j;
	n=strlen(str);
	temp=(char **)calloc(n,sizeof(char *));
	for(i=0;i<n;i++)
		temp[i]=calloc(n,sizeof(char));
	printf("size:%d\n",sizeof(temp));
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
//		printf("%d,%d\n",i,j);
		temp[i][j]='X';
	}
	
//	for(i=0;i<n;i++,printf("\n"))
//	for(j=0;j<n;j++)
//		printf("%c ",temp[i][j]);
	
	for(i=0;i<n;i++)
		temp[i][n/2]=str[i];
	for(j=0;j<n;j++)
		temp[n/2][j]=str[j];
	for(i=0;i<n;i++,printf("\n"))
	for(j=0;j<n;j++)
		printf("%c ",temp[i][j]);
		


}
