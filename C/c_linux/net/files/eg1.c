#include<stdio.h>
main()
{
	FILE *fp;
	char c;
	fp=fopoen("test.txt","r");
	while((c=fgetc(fp))!=EOF)
	{
		printf("\n%c",c);
		printf("--%d",fp->level);
	}
	fclose(fp);


}
