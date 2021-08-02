#include<stdio.h>
#include<string.h>
int main()
{
	char string[20];
	puts("enter a string");
	gets(string);
	char a[5],b[5],c[5],d[5];
	int len,n=2,num,temp;
	len=strlen(string);
	
//	if((len/2)%2==0)
//		strcpy(a,num+len/2);
//	else
//		strcpy(a,num+(len/2)-1);
	//puts(a);
	num=atoi(string);
//	printf("%d",num);
	temp=num;
	int rem,i=1,sum=0;
	while(1)
	{
		rem=temp%100;
		temp=temp/100;
		while(i<4)
		{
			sum+=temp%pow(10,i);
			if(sum==rem)
				break;
			i++;
		}
		
	}
}
