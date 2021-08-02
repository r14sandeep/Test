#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *remov(char *,char *);
main(int argc,char **argv)
{
	FILE *fp;
	char *buf,*found;
	int size=0,i,j,k;
	fp=fopen(argv[1],"r");
//	while(fgetc(fp)!=EOF)
//		size++;
	fseek(fp,0,2);
	size=ftell(fp);
	rewind(fp);
	fclose(fp);
	buf=calloc(1,size+1);
	fp=fopen(argv[1],"r");
	fread(buf,size,1,fp);
	fclose(fp);
	buf=remov(buf,argv[2]);	
	fp=fopen(argv[1],"w");
	for(i=0;i<size;i++)
		fputc(buf[i],fp);


	fclose(fp);
}
char *remov(char *buf,char *s1)
{
	char *found;
	int i,j,k;
	i=strlen(s1);
	found=buf;
	while((found=strstr(found,s1)))
	{
		memmove(found,found+i,strlen(found+i)+1);	


	}
	return buf;
	//fclose(buf);
}
