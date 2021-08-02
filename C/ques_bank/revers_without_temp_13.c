#include<stdio.h>
int main()
{
	char str[14]="helloworld";
	int i,j,n;
	n=strlen(str);
	for(i=0,j=n-1;i<j;i++,--j)
	{
		str[i]^=str[j]^=str[i]^=str[j];
	}
	puts(str);
}
