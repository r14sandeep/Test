#include"header.h"
main()
{
	int p[2],i;	
	pipe(p);
	char s[100];	
	if(fork())
	{
		puts("enter a string");
		gets(s);
		write(p[1],s,strlen(s)+1);
		sleep(1);
		read(p[0],s,strlen(s)+1);
		puts(s);
		exit(0);
	}
	else
	{
		printf(">>>>>\n");
//		sleep(10);
		read(p[0],s,strlen(s)+1);
    printf("%d\n",strlen(s));
	//	a=strlen(s);
		for(i=0;s[i];i++)
		{
			if(s[i]==' ')
			{
				memmove(s+i,s+i+1,strlen(s+i+1)+1);
				i--;
			}
			//printf("%c",s[i]);
		}
//		printf("%s \n",s);
		write(p[1],s,strlen(s)+1);
		sleep(1);
               exit(0);


	}

}
