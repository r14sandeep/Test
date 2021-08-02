#include<stdio.h>
#include<string.h>
main()
{
	char s1[100],s2[100];
	int p,n,i;
	puts("enter s1:");
	gets(s1);
	puts("enter s2:");
	gets(s2);
	n=strlen(s2);
	printf("enter position from 0 to %d:",strlen(s1));
	scanf("%d",&p);
	if(p>strlen(s1))
	{
		printf("invalid position\n");
		return;
	}
	memmove(s1+n+p,s1+p,strlen(s1+p)+1);
//	strcpy(s1+n+p,s1+p);
	puts(s1);
//strcpy(s1+p,s2);
	memmove(s1+p,s2,strlen(s2));
	puts(s1);
	


}

