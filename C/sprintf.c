#include<stdio.h>
int main()
{
	FILE *fp;
	char *buf;
	buf=calloc(1,20);
	fp=fopen("file.txt","r");
//	sprintf(buf,"%s","hello");
//	puts(buf);
//	fwrite(buf,1,strlen(buf),fp);
//	fclose(fp);
//	fseek(fp,0,0);
	while(fscanf(fp,"%s",buf)!=EOF)
	{
		puts(buf);
	
	}
	fclose(fp);

	fp=fopen("file.txt","w");
//	while(fprintf(fp,"%s",gets(buf))!=NULL);
	while(strcmp(buf,"end")!=0)
	fprintf(fp,"%s",gets(buf));
	fclose(fp);
}
