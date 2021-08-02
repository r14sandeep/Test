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
		int v;
		for(v=1;v<=10;v++)
		write(p[1],&v,4);
		
		exit(0);
	}
	else
	{
		int i;
		do{
		read(p[0],&i,4);
		printf("v=%d\n",i);
		}while(i<10);
	}
		exit(0);
}
