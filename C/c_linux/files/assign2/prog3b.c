#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *hide(char *,char *);
main(int argc,char **argv)
{
	FILE *fp;
	char *buf,*found;
	int size=0,i,j,k;
	fp=fopen(argv[1],"r");
	while(fgetc(fp)!=EOF)
		size++;
	fclose(fp);
	buf=calloc(1,size+1);
	fp=fopen(argv[1],"r");
	fread(buf,size,1,fp);
	fclose(fp);
	buf=hide(buf,argv[2]);	
	fp=fopen(argv[1],"w");
	for(i=0;i<size;i++)
		fputc(buf[i],fp);


	fclose(fp);
}
char *hide(char *buf,char *s1)
{
	char *found;
	int i,j,k;
	found=buf;
	while(found=strstr(found,s1))
	{
		j=found-buf;
		k=j;
		while(j<k+strlen(s1))
		{
			buf[j]='*';
			j++;
		}
	}
	return buf;
	//fclose(buf);
}
