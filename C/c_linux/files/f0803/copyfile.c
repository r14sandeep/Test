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
	for(i=0;i<size;i++)
	{
		buf[i]=fgetc(fp);
		//printf("%c\n",buf[i]);
	}
	fclose(fp);
	//printf("buf:%s\n",buf);
	fp=fopen(argv[2],"w");
	for(i=0;i<size;i++)
		fputc(buf[i],fp);
	fclose(fp);
	printf("*****copied successfully*****\n");
	free(buf);
}
