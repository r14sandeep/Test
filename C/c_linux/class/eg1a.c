#include<stdio.h>
#include<string.h>
main()
{
	char *found,s1[100],s2[100];
	int cnt=0;
	puts("enter s1");
	gets(s1);
	puts("enter s2");
	gets(s2);
	found=s1;
	while(found=strstr(found,s2))
	{
		printf("found at %d\n",found-s1);
		cnt++;
		found++;


	}		



printf("occurannce=%d\n",cnt);


}
