#include<stdio.h>
main()
{
	FILE *fp;
	char ch;
	fp=fopen("testfile","r");
	if(fp==NULL)
	{
		printf("error:file is not present\n");
		return;
	}
	ch=fgetc(fp);
	printf("%c",ch);
	ch=fgetc(fp);
	printf("%c",ch);


	
}
