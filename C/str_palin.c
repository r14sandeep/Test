#include<stdio.h>
int main()
{
	char str[10];
	int index1,index2,len;
	puts("enter a strintg:");
	gets(str);
	len=strlen(str);
	for(index1=0,index2=len-1;index1<index2;index1++,index2--)
	{
		if(str[index1]!=str[index2])
		{
			printf("not a pallindrom\n");
			break;
		}	
	}
	if(!(index1<index2))
		printf("pallindrom\n");

}
