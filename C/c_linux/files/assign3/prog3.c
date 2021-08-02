///remove the lines containing <=5 chars
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *line(char *,int);
main(int argc,char **argv)
{
	FILE *fp;
	int size;
	char *buf=0;
	fp=fopen(argv[1],"r");
	
	//fp=fopen("","r");
	if(fp==0)
	{
		printf("file not found\n");
		return;
	}
	fseek(fp,0,2);
	size=ftell(fp);
	//printf("%d\n",size);
	rewind(fp);
	buf=calloc(1,size+1);
	//printf("%d\n",sizeof(buf));
	fread(buf,size,1,fp);
	//printf("%d\n",size);
	fclose(fp);
	//printf("%d\n",size);
	buf=line(buf,size);
	fp=fopen(argv[1],"w");
	
	fputs(buf,fp);
	fclose(fp);

}
char *line(char *buf,int size)
{
	int i,cnt=0;
	char ch;
//	FILE *fp;
	//fp=fopen("s1","r");
	//printf("%d\n",size);
	for(i=0;i<size;i++)
	{	
		//if((ch=fgetc(fp))!=EOF);
		if(ch=buf[i]);
		{
		//printf("%c",ch);
		cnt++;
		//printf("%d\n",cnt);
		if(ch=='\n')
		{	   
			if(cnt<=6)
	  	     	{
				memmove(buf+i-cnt+1,buf+i+1,strlen(buf+i+1)+1);
				i=0;
				size=size-cnt;
			}
		cnt=0;
		
		}	
		}
	
	}
//	fclose(fp);
	return buf;
}
