#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str[20];
main()
{
	
	if(fork())
	{
		sleep(1);
		printf("str in parent %s \n",str);
		exit(0);
	}
	else
	{
		strcpy(str,"india");
		printf("str is child %s \n",str);
		sleep(3);
		exit(0);
	}

}
