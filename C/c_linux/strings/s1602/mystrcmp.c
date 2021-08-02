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
	int l1,l2,cnt=0,i;
	l1=strlen(s1);
	l2=strlen(s2);
	if(l1==l2)
	{
		for(i=0;i<l1;i++)
		{	
			if(s1[i]==s2[i])
			{	cnt++;
				if(cnt==l1)
					return 0;
			}
			else if(s1[i]>s2[i])
					return 1;
			else return -1;
		}
	}
	else
		if(l1>l2)		
			for(i=0;i<l1;i++)
			{	if(s1[i]>s2[i])
					return 1;
				if(s1[i]<s2[i]) return -1;
			}
		else
			for(i=0;i<l2;i++)
			{	if(s1[i]>s2[i])
					return 1;
				if(s1[i]<s2[i]) return -1;
			}
		
	
}
