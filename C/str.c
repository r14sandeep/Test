#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*int main()
{
       char str[10],temp;
        int len,index1,index2;
        puts("enter a string:");
        gets(str);
         len=strlen(str);
        for(index1=0,index2=len-1;index1<index2;index1++,index2--)
        {
                 temp=str[index1];
                  str[index1]=str[index2];
                  str[index2]=temp;
         }
         printf("reverse of the string is:");
         puts(str);
}*/

int main()
{
	char *str,temp;
	int num1,index1=0,index2,len,rem,num,dig_cnt=0;
	printf("enter a num:");
	scanf("%d",&num1);
	num=num1;
	while(num)
	{
		rem=num%10;
		num/=10;
		dig_cnt++;

	}
	str=calloc(1,sizeof(char)*cnt);
	num=num1;
	while(num)
	{
		rem=num%10;
		str[index1++]=rem+48;
		num/=10;
	}
	len=strlen(str);
        for(index1=0,index2=len-1;index1<index2;index1++,index2--)
        {
                 temp=str[index1];
                  str[index1]=str[index2];
                  str[index2]=temp;
         }
	puts(str);

}
