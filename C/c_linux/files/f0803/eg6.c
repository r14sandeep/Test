#include<stdio.h>
main()
{
	FILE *fp;
	char ch;
	fp=fopen("testfile","r");
	
	printf("%lu\n",ftell(fp));
	printf("%c",fgetc(fp));


}
