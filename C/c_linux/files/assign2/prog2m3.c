#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp,*fp2;
	char buf[100];
	int size=0,i;
	fp=fopen(argv[1],"r");
//	fseek(fp,0,2);
//	size=ftell(fp);
//	buf=calloc(1,size+1);
//	fread(buf,size,1,fp);
//	fclose(fp);
	fp2=fopen("temp","a");
	while(fscanf(fp,"%s",buf)!=EOF)	
	{
		if(buf[strlen(buf)-1]=='.')
		{
			fputs(buf,fp2);
			fscanf(fp,"%s",buf);
			buf[0]=buf[0]-32;
		}
		
			fputs(buf,fp2);
	}
	fclose(fp);
	fclose(fp2);
}
