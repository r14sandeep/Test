#include<stdio.h>
#include<string.h>
int mystrchr(char *,char *);
main()
{
	char a[100],b[100];
	int p;
	puts("enter a string:");
	gets(a);
	puts("enter b string:");
	gets(b);
	p=mystrchr(a,b);
	printf("%d\n",p);
}
int mystrchr(char *s1,char *s2)
{	
	int cnt=0,i,j;
		
	for(i=0,j=0;s1[i],s2[j];i++,j++)
	{	
			if(s1[i]==s2[j])
			{	cnt++;
			}
			else if(s1[i]>s2[j])
					return 1;
			else if(s1[i]<s2[j])
					return -1;

	}
	return 0;
/*	if(s1[i]==s2[j])	
		return 0;
	else if(s1[i]>s2[j])
		return 1;
	else if(s1[i]<s2[j])
		return -1;	
*/
}
