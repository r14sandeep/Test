////print reverse of given line from file
#include<stdio.h>
#include<string.h>

main(int argc,char **argv)
{
	FILE *fp;
	char *p[100];
	int a,i;
	fp=fopen(argv[1],"r");
	while(p[100]=fgets(argv[1],100,stdin))	
	{	
		a=strlen(p[100]);
		for(i=a;i<0;i--)
			printf("%c",p[0][i]);
					
		return;
	}	

}















