#include<stdio.h>
int main()
{
	char str[100];
	FILE *fp;
	fp=fopen(__FILE__,"r");
	while(fgets(str,100,fp)!=NULL)
		puts(str);

}
