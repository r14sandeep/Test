#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp,*fp2;
	char buf[100];
	int size=0,i;
	fp=fopen(argv[1],"r");
	fp2=fopen("temp","w");
	while(fgets(buf,100,fp)!=NULL)	
	{
		for(i=0;buf[i];i++)
		{
			if(buf[i]=='.')
			{
				i++;
				buf[i]=buf[i]-32;
			}	
		}
		fputs(buf,fp2);
	}
	fclose(fp);
	fclose(fp2);
}
