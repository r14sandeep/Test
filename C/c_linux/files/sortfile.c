#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp;
	char buf[100],*p,*temp2;
	int size,cnt=0,i,j;
	fp=fopen(argv[1],"r");
//	fseek(fp,0,2);
//	size=ftell(fp);
//	rewind(fp);
//	buf=calloc(1,size+1);
//	fread(fp,buf,1,size);
//	fclose(fp);
	while(fgets(buf,100,fp)!=NULL)
	{
		p=buf;
		cnt++;
	}
	for(i=cnt-1;i>=0;i--)
		for(j=0;j<i;j++)
			if(strlen(p[j])>strlen(p[j+1]))
			{
				temp2=p[j];
				p[j]=p[j+1];
				p[j+1]=temp2;
			}
	for(i=0;i<cnt;i++)
		printf("%s\n",p[i]);
	fclose(fp);
}
