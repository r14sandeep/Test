#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp;
	char s[200];
	int size,l=0,w=0;
	fp=fopen(argv[1],"r");
	while(fgets(s,200,fp)!=NULL)
	{
		l++;
	}
	rewind(fp);
	while(fscanf(fp,"%s",s)!=EOF)
		w++;
	size=ftell(fp);
	printf("%d %d %d\n",l,w,size);
	fclose(fp);

}
