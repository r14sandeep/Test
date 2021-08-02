#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp;
	char str[10];
	fp=fopen(argv[1],"r");
	while(fgets(str,10,fp))
	{
		printf("%s",str);
	//	sleep(5);
	}
	fclose(fp);




}
