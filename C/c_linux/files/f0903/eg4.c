#include<stdio.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp;
	int cnt=0;
	char linebuf[100];
	fp=fopen(argv[1],"r");
	while(fgets(linebuf,100,fp))
	{
		cnt++;
		if(strstr(linebuf,argv[2]))
			printf("%2d:%s",cnt,linebuf);
	}
	fclose(fp);
	


}
