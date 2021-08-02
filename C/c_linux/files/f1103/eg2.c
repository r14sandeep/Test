#include<stdio.h>
main()
{
	FILE *fp;
	int v;
	fp=fopen("f2","r");
	while(fread(&v,sizeof(int),1,fp)==1)
		printf("v=%d\n",v);
	fclose(fp);

}
