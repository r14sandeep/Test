#include<stdio.h>
#include<string.h>
void rev(char *p)
{
	puts(p);
	int i,j,n;
	char temp;
	n=strlen(p);
	for(i=0,j=n-1;i<j;i++,j--)
	{
		temp=p[i];
		p[i]=p[j];
		p[j]=temp;
	}
	printf("%s ",p);

}
int main()
{
	char str[20],temp[20];
	puts("enter a string:");
	gets(str);
	int i,j=0;
	for(i=0;str[i];i++)
		if(str[i]==32)
		{	
			
			memmove(temp,str+j,strlen(str+i-1)+1);
			j=i+1;
			rev(temp);
		}
	
	memmove(temp,str+j,strlen(str+i-1)+1);
	
	rev(temp);
//	puts(str);

}
