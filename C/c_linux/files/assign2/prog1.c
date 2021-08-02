//prog to remove extra spaces,new lines in a given file.......
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp;
	char *buf;
	int size,i;
	fp=fopen(argv[1],"r");
	fseek(fp,0,2);
	size=ftell(fp);
	rewind(fp);
	buf=calloc(1,size+1);
	fread(buf,size,1,fp);
	fclose(fp);
	for(i=0;i<size;i++)
	{
	if(((buf[i]==' ')&&(buf[i+1]==' '))||((buf[i]=='\n')&&(buf[i+1]=='\n')))
	{	memmove(buf+i,buf+i+1,strlen(buf+i)+1);
		i--;
	}
	}
	fp=fopen(argv[1],"w");
	fputs(buf,fp);
	fclose(fp);
	
}
