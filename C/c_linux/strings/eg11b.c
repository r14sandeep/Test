/***prog to remove extra repetations in given string****/
#include<stdio.h>
#include<string.h>
main()
{
char s[100];
int i,j;
puts("enter s");
fgets(s,100,stdin);
s[strlen(s)-1]='\0';
for(i=0;s[i];i++)
{
//search the s[i] ffrom i+1 onwards
	for(j=i+1;s[j];j++)
	{
	//if j index contains s[i],remove it:
		if(s[i]==s[j])
		{
			memmove(s+j,s+j+1,strlen(s+j+1)+1);
			j--;
		}
	}

}
printf("%s\n",s);
}
