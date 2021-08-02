#include<stdio.h>
#include<string.h>
main()
{
	char s1[100],s2[100];
	printf("enter s1");
	gets(s1);
	printf("enter s1");
	gets(s2);
	printf("addrs of s1 %u\n",s1);
	//////////****search for s2 in s1
	printf("return value of strstr is %u\n",strstr(s1,s2));
	printf("found at %d\n",strstr(s1,s2)-s1);
}
