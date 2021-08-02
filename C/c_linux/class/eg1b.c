#include<stdio.h>
#include<string.h>
main()
{
	char *found,s1[100],s2[100];
	int j,k;
	puts("enter s1");
	gets(s1);
	puts("enter s2");
	gets(s2);
	found=s1;
	k=strlen(s2);
	while(found=strstr(found,s2))
	{
	j=found-s1;
	memmove(s1+j,s1+j+k,strlen(s1+j)+1);
	

	}		



printf("%s\n",s1);


}
