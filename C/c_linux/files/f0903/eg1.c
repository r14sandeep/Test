#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp;
	char str[10];
	fp=fopen(argv[1],"r");
	fgets(str,10,fp);
	printf("%s\n",str);
	fclose(fp);




}
