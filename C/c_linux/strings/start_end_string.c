/*
Input : s = "geeksforgeeks"
        begin = "geeks"
        end = "for"
Output : 1

Input : s = "vishakha"
        begin = "h"
        end = "a"
Output : 2
Two different sub-strings are "ha" and "hakha".
*/
#include<stdio.h>
#include<string.h>
int main()
{
	char str[20],begin[10],end[10],*add,*ad,*found;
	puts("enter str,begin,end");
	gets(str);
	gets(begin);
	gets(end);
	found=str;
	add=strstr(str,begin);
//	printf("%p\n",add);
	int n=strlen(begin),ind,m;
	m=strlen(end);
//	printf("%p\n",&str[0]);
	ind=&str[0]-add;
//	printf("%d\n",ind);
	ad=strstr(str+ind+n,end);	
//	printf("%p\n",ad);
	char *temp,res[20];
	int cnt=0;
	while(found=strstr(found,begin))
	{	
		printf("f:%p\n",found);
		temp=found;
		while(temp=strstr(temp+strlen(end),end))
		{
		
			printf("t:%p\n",temp);
			cnt++;
			temp++;
		}
		found++;
	}
	printf("cnt:%d\n",cnt);
}
