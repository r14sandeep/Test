#include"header.h"
int main()
{
	int p1[2],p2[2];
	pipe(p1);pipe(p2);
	char rdbuff[100],wrbuff[100];
	while(1)
	{
		if(fork()==0)
		{
			puts("enter masg to parent:");
			gets(wrbuff);
			write(p1[1],wrbuff,strlen(wrbuff)+1);
			read(p2[0],rdbuff,100);
			printf("from parent:%s\n",rdbuff);
			
		}
		else
		{
			read(p1[0],rdbuff,100);
			printf("from child:%s\n",rdbuff);
			puts("enter masg to child:");
			gets(wrbuff);
			write(p2[1],wrbuff,strlen(wrbuff)+1);
	
		}

	}


}
