/*****insert s2 in specified positionn of s1****////
#include<stdio.h>
#include<string.h>
main()
{
	char s1[20],s2[20],temp[20];
	int p,i;
	printf("enter s1\n");
	gets(s1);
	printf("%d\n",strlen(s1));
	printf("enter s2\n");
	gets(s2);
	printf("enter position where s2 is to be inserted");
	scanf("%d",&p);
	if(p>strlen(s1))
	{	
		printf("invalid position\n");
		return;
	}
//	for(i=0;i<strlen(s1+p);i++)
//		temp[i]=s1[p+i];
	//memmove(s1+strlen(s2)+p,s1+p,strlen(s1+p)+1);
	memmove(temp,s1+p,strlen(s1+p)+1);
	strcpy(s1+p,s2);
//	strcpy(s1+strlen(s1),temp);
	strcat(s1,temp);
	printf("s1=%s\n",s1);

}
