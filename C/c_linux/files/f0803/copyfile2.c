////implement copy command using only one pointer
#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fp;
	char *buf;
	int size=0,i;
	if(argc!=3)
	{
		printf("enter source ,dest files\n");
		return;
	}
	fp=fopen(argv[1],"r");
	fseek(fp,0,2);
	size=ftell(fp);
	printf("size=%d\n",size);
	rewind(fp);
	buf=calloc(1,size+1);
	fread(buf,1,size,fp);
	fclose(fp);
	fp=fopen(argv[2],"w");
	fwrite(buf,size,1,fp);
	fclose(fp);
	free(buf);
}
