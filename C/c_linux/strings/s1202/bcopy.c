#include<stdio.h>
#include<string.h>
void mybcopy(char *s1,char *s2,int n)
{
	char *p;
	int cnt=0,i;
	for(i=0;i<n;i++)
	{
		s2[i]=s1[i];
	}
	puts(s1);
	puts(s2);
	
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
	bcopy(s1,s2,5);
	printf("s1:%s s2:%s \n",s1,s2);
	mybcopy(s1,s2,5);
//	p=mystrcat(s1,s2);
//	printf("s1:%s s2:%s \n",s1,s2);
	//puts(p);

}
