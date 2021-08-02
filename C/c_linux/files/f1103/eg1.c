#include<stdio.h>
main()
{
	int a[]={100,99,55,44,66};
	FILE *fp;
	int i;
	char buf[100];
	fp=fopen("f1","r");
//	for(i=0;i<5;i++)
//	fprintf(fp,"%d",a[i]);
	while(fscanf(fp,"%s",buf)!=EOF)
		puts(buf);
	fclose(fp);
	fp=fopen("f2","w");
	
	for(i=0;i<5;i++)
	fwrite(a+i,4,1,fp);
	
	fclose(fp);



}
