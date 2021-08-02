/****prog to print multople words seperated by space,if more than one space there means delets the spaces****///
#include<stdio.h>
#include<string.h>
main()
{
	char s[100];
	int i,cnt=0;
	printf("enter s");
	scanf("%[^\n]s",s);

	
	printf("i/p s=%s\n",s);
	
	for(i=0;i<strlen(s);i++)
	{
		if((s[i]==' ')&&(s[i+1]==' '))
		{	
			memmove(s+i,s+i+1,strlen(s+i+1)+1);
			i--;
		}
	}

	

printf("s=%s\n",s);




}
