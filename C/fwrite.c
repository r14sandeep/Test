#include<stdio.h>
int main()
{
	FILE *fp;
	int v,i;
	fp=fopen("file.txt","rw+");
	for(i=0;i<8;i++)
		fwrite(&i,4,1,fp);
	char s[10]="sandeep";
	fprintf(fp,"%s",s);
	fseek(fp,0,0);
	while(fread(&v,sizeof(int),1,fp)==1)
	printf("%d\n",v);
	fclose(fp);


}
