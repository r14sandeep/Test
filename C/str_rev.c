#include<stdio.h>
#include<string.h>
/*int main()
{
	char temp,str[10]="hyderabad";
	int len;
	len=strlen(str);
	int index1,index2;
	for(index1=0,index2=len-1;index1<index2;index1++,index2--)
	{
		temp=str[index1];
		str[index1]=str[index2];
		str[index2]=temp;
		
	}
	puts(str);
}*/
int main()
{
	int index=0;
	char str1[10]="votary";
	char str2[10];
	char *ptr1,*ptr2;
	ptr1=str1;
	ptr2=str2;
	while(*ptr1!='\0')
	{
		index++;
		ptr1++;

	}
	while(index>0)
	{
		--ptr1;
		*ptr2=*ptr1;
		ptr2++;
		index--;
	}
//	*ptr2=NULL;
	puts(str2);
}

