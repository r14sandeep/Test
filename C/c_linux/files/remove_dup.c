#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
	FILE *fp;
        int size,cnt=0,i;
        char *buf,*found,word[20];
        fp=fopen(argv[1],"rw");
        fseek(fp,0,2);
        size=ftell(fp);
        rewind(fp);
        buf=calloc(1,size+1);
        fread(buf,size,1,fp);
	puts(buf);	
	while(sscanf(buf,"%s",word)!=EOF)
	{
		printf("word:%s\n",word);
		found=buf;
/*		while(found=strstr(found,word))
		{
			memmove(found,found+strlen(word),strlen(found+strlen(word))+1);
	puts(buf);
			found++;
		}
		puts(buf);
*/
	buf+=strlen(word)+1;
	
	}
	fputs(buf,fp);
	fclose(fp);
}
