#include<stdio.h>
main()
{
	FILE *fp;
	char c;
	fp=fopoen("test.txt","r");
	printf("\n%x",fp->flags);
	
	fp=fopoen("test.txt","rb+");
	
	printf("\n%x",fp->flags);
	fclose(fp);


}
