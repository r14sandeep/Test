//////w.a.p to find the size of given file

#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch;
	int cnt=0;
	if(argc<2)
	{
	printf("error:file name is not supplied\n");
	printf("use:./findsize filename\n");
	return;
	}
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("file not found\n");
		return;
	}
	while((ch=fgetc(fp))!=EOF)
	cnt++;
	fclose(fp);
	printf("size is %d\n",cnt);
}	
