/***prog to remove extra repetations in given string****/
#include<stdio.h>
#include<string.h>
main()
{
char s[100];
int i,j;
puts("enter s");
gets(s);
for(i=0;s[i];i++)
{
	for(j=0;j<i;j++)
	{
loop:		if(s[i]==s[j])
		{
			strcpy(s+i,s+i+1);
			goto loop;
		}
	}

}
printf("%s\n",s);
}
