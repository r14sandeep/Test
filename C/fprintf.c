#include<stdio.h>
int main()
{
	int v;
	FILE *fp;
	fp=fopen("file2.txt","rw+");
	for(v=1;v<8;v++)
		fprintf(fp,"%d",v);
	fseek(fp,0,0);
	printf("\n");
	char c;
	while(fscanf(fp,"%d%c",&v,&c)!=EOF)
		printf("%d %c\n",v,c);	
	fclose(fp);
}
