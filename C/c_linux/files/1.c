#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen(__FILE__,"r");
	char buf[200];
	int size;
//	fseek(fp,0,2);
//	size=ftell(fp);
//	rewind(fp);
	fread(buf,200,1,fp);
	puts(buf);
/*	char c;
	while((c=fgetc(fp)!=EOF))
		printf("%c",c);
*/
}
