#include<stdio.h>
main()
{
	FILE *fp=0;
	char ch;
	fp=fopen("testfile","r");
	printf("%lu\n",ftell(fp));
	printf("%c\n",fgetc(fp));
	fseek(fp,5,1);
	printf("%c\n",fgetc(fp));
	printf("%lu\n",ftell(fp));
	fseek(fp,-3,1);
	printf("%c\n",fgetc(fp));
	//printf(fp,-3,2);






}
