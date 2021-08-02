/******in a string remove all the non alphabets*****///
#include<stdio.h>
#include<string.h>

main()
{
	char s[100];
	int i;
	puts("enter s");
	gets(s);
//printf("%d ", 'z');	
	for(i=0;i<strlen(s);i++)
	{
/*loop:*/		if(!(((s[i]>64)&&(s[i]<91))||((s[i]>96)&&(s[i]<123))))
		{	
			printf("%c ",s[i]);
			memmove(s+i,s+i+1,strlen(s+i)+1);
			//goto loop;
			i--;
		}
	}
	printf("s=%s\n",s);
	




}

