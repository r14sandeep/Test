#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
	FILE *fp;
	char **buf,s[100],temp;
	int cnt=0,i=0,j,k;
	fp=fopen(argv[1],"r");
	while(fgets(s,100,fp)!=NULL)
	{
		cnt++;
	}
	rewind(fp);
	buf=(char **)calloc(cnt,sizeof(char *));
	while(fgets(s,100,fp)!=NULL)
	{
		buf[i]=0;
		buf[i]=(char *)calloc(1,sizeof(s));
		strcpy(buf[i],s);
		i++;

	}
	fclose(fp);
	for(i=0;i<cnt;i++)
	for(k=0;k<cnt;k++)
		for(j=k+1;j<cnt;j++)
		{
			//puts(buf[i]);
			//if(strcmp(buf[i][k],buf[i][j])>0)
			puts(buf[i]);			
			if(buf[i][k]<buf[i][j])
			{
				puts("*****");
				temp=buf[i][k];
				buf[i][k]=buf[i][j];
				buf[i][j]=temp;
			}
			puts(buf[i]);			
		}
	fp=fopen(argv[1],"w");
	for(i=0;i<cnt;i++)
		fputs(buf[i],fp);
	fclose(fp);
}
