#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fp;
	int size,i;
	char *buf;
	if(argc!=3)
	{
		printf("enter source and target file\n");
		return;

	}
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("source file not exist\n");
		return;
	}
	fseek(fp,0,2);

	size=ftell(fp);
	rewind(fp);
	buf=calloc(1,size+1);
	fread(buf,size,1,fp);
	fclose(fp);
	fopen(argv[2],"w");
	for(i=0;i<size;i++)
	{
		fputc(buf[i],fp);

	}
	free(buf);
	fclose(fp);
	printf("*****copy success*****\n");



}
