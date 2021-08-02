#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	char *buf,*found;
	FILE *fp;
	int size=0,len;
	if(argc!=3)
	{
		printf("error:i/p as ./a.out filename1 string\n");
		return;
	}
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("error:file not present\n");	
		return;
	}
	while(fgetc(fp)!=EOF)
		size++;
	//fclose(fp);
	buf=calloc(1,size+1);
	fread(buf,size,1,fp);
	fclose(fp);
	found=buf;
	len=strlen(argv[2]);
	while(found=strstr(found,argv[2]))
		memmove(found,found+len,strlen(found+len)+1);
	fp=fopen(argv[1],"w");
	fputs(buf,fp);
	fclose(fp);

}

