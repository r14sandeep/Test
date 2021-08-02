#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch;
	fp=fopen(argv[1],"r");
//	ch=fgetc(fp);
	ch=getchar();
	printf("%c\n",ch);
	fclose(fp);

}
