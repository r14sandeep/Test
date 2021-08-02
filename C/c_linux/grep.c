#include<stdio.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp;
	char buf[100];
	fp=fopen(argv[2],"r");
	while(fgets(buf,100,fp)!=NULL)	
	{
		//	puts(buf);
		if(strstr(buf,argv[1]))
		//	puts(buf);
		printf("%s ",buf);

	}
fclose(fp);
}
