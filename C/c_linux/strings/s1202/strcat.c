#include<stdio.h>
#include<string.h>
char *mystrcat(char *s1,char *s2);
char *mystrncat(char *s1,char *s2,int n)
{
	char *p;
	int cnt=0,i;
	p=s1;
	while(*p)
	{
		p++;
		cnt++;
	}
	for(i=0;i<n;i++)
	{
		s1[cnt]=s2[i];
		cnt++;
	}
	s1[cnt]='\0';
	return s1;
}
main()
{
	char s1[20];
	char s2[20],*p;
	puts("enter s1,s2");
	gets(s1);
	gets(s2);
	printf("s1=%d\n",strlen(s1));
	printf("s2=%d\n",strlen(s2));
//	strcat(s1,s2+1);
//	strcat(s1+2,s2+1);
	//p=mystrncat(s1,s2,5);
	p=strncat(s1,s2,5);
//	p=mystrcat(s1,s2);
	//printf("s1:%s s2:%s \n",s1,s2);
	puts(p);

}
char *mystrcat(char *s1,char *s2)
{
	int i,j,cnt=0;
	char *p;
	p=s1;
	while(*p)
	{
		p++;
		cnt++;
	}
	for(i=0;s2[i];i++)
	{
		s1[cnt]=s2[i];
		cnt++;
	}
	s1[cnt]='\0';
	return s1;
}
