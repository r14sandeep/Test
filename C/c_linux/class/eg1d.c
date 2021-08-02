#include<stdio.h>
#include<string.h>
main()
{
	char s1[100],s2[100];
	char *found;
	int n,i,j,k;
	puts("enter s1");
	gets(s1);
	puts("enter s2");
	gets(s2);
	found=s1;
	
	while(found=strstr(found,s2))
	{
		k=found-s1;
		j=strlen(s2);
		for(i=k;i<k+j;i++)
		{
		s1[i]='*';
		}
	}		
printf("%s\n",s1);

}
