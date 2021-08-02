#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *replace(char *s1,char *s2,char *buf)
{
	int l1,l2,size;
	
	char *found;
	l1=strlen(s1);
	l2=strlen(s2);
	size=strlen(buf);
	//found=buf;
	if(l2>l1)
	{
		size=size+(l2-l1);	
		buf=realloc(buf,size+1);
		found=buf;
		while(found=strstr(found,s1))
		{
			memmove(found+(l2-l1),found,strlen(found)+1);		
			strncpy(found,s2,l2);
			found=found+l2;

		}
	}
	if(l1>l2)
	{
		found=buf;
		while(found=strstr(found,s1))
		{
			memmove(found+l2,found+l1,strlen(found+l1)+1);
			strncpy(found,s2,l2);
			found=found+l2;

		}


	}
	return buf;

}
main(int argc,char **argv)
{
	FILE *fp;
	char *buf;
	int size;
	fp=fopen(argv[1],"r");
	fseek(fp,0,2);
	size=ftell(fp);
	rewind(fp);
	buf=calloc(1,size+1);
	fread(buf,size,1,fp);
	fclose(fp);
	buf=replace(argv[2],argv[3],buf);
	fp=fopen(argv[1],"w");
		fputs(buf,fp);
}
