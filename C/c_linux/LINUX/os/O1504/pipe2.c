#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str[20];
main()
{
	int p[2];
	pipe(p);	
	if(fork())
	{
		sleep(1);
		read(p[0],str,20);
		printf("str in parent %s \n",str);
		exit(0);
	}
	else
	{
		strcpy(str,"india");
		printf("str is child %s \n",str);
		//sleep(3);
		write(p[1],str,strlen(str));
//		str="1234";
		strcpy(str,"1234");
		write(p[1],str,strlen(str));
		sleep(3);
		exit(0);
	}

}
