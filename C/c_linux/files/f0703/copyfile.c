#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp1,*fp2;
	char ch;
	if(argc!=3)
	{
		printf("enter source and target file\n");
		return;

	}
	fp1=fopen(argv[1],"r");
	if(fp1==NULL)
	{
		printf("source file not exist\n");
		return;
	}
	/*fp2=fopen(argv[2],"r");
	if(fp2==NULL)
	{
		printf("dest file not exist\n");
		return;
	}*/
	fp2=fopen(argv[2],"w");
	while((ch=fgetc(fp1))!=EOF)
	{
		fputc(ch,fp2);

	}
	fclose(fp1);
	fclose(fp2);
	printf("*****copy success*****\n");



}
