#include<stdio.h>
void myitoa(int n)
{
	printf("%d\n",n);
	char temp;
	char str[10];
	int index1,index2,i=0;
	while(n>0)
	{
		str[i++]=(n%10)+48;
		n/=10;
	}
	str[i]='\0';
	for(index1=0,index2=i-1;index1<index2;index1++,index2--)
	{
		temp=str[index1];
		str[index1]=str[index2];
		str[index2]=temp;
	}
	puts(str);
//	return str;
}
int mysprintf(char *str,char *format,int n)
{
//	printf("%s\n",format);
	if(strcmp(format,"%d")==0)
		myitoa(n);
	
//	puts(str);


}
int main()
{
	char str[10],ch='A';
	int c=12;
	mysprintf(str,"%d",c);
	puts(str);
}
