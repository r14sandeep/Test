#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp;
	char *buf;
	int cnt=0,size;
	fp=fopen(argv[1],"r");
	fseek(fp,0,2);	
	size=ftell(fp);
	buf=calloc(1,size+1);
	fread(buf,size,1,fp);
	fclose(fp);
	
}
