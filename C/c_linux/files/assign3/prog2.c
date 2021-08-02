#include<stdio.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch,*buf;
	int i,size;

	fp=fopen(argv[1],"r");	
	fseek(fp,0,2);
	size=ftell(fp);
	buf=calloc(buf,size,1,fp);
	fread(buf,size,1,fp);
	fclose(fp);
	for(i=0;)




}
