#include<stdio.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp;
	int cnt=0;
	char linebuf[100],*found;
	fp=fopen(argv[1],"r+");
	while(fgets(linebuf,100,fp))
	{
		if(found=strstr(linebuf,argv[2]))
		{
			memset(found,'*',strlen(argv[2]));
			fseek(fp,-1*strlen(linebuf),1);		
			fputs(linebuf,fp);
		}


	}
	fclose(fp);
	


}
