#include<stdio.h>
char *mystrstr(char *,char *);
main()
{
	char s1[100],s2[100],*p;
	puts("enter s1:");
	gets(s1);
	puts("enter s2:");
	gets(s2);
	p=mystrstr(s1,s2);
	printf("found at %u\n",p);

}
char *mystrstr(char *s1,char *s2)
{
	int i,j;
	for(i=0;s1[i];i++)
		if(s1[i]==s2[0])
		{
			for(j=1;s2[j];j++)
			{
				if(s1[i+j]==s2[j])
					break;
			}	
			if(s2[j]=='\0')
				return (s1+i);
			
		}
	return NULL;

}
