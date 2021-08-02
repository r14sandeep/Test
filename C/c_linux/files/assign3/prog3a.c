///remove the lines containing <=5 chars
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *line(char *,int);
main(int argc,char **argv)
{
	FILE *fp,*fp1;
	int size,i,cnt=0;
	char a[100],*buf,b[100];
	fp=fopen(argv[1],"r");
	fp1=fopen("temp","w");
	while(fgets(a,100,fp))
	{
		if(strlen(a)>6)
		{
		//	b[++cnt]=a;
		fputs(a,fp1);	
		}		

	}
	fclose(fp);
/*	fp=fopen(argv[1],"w");
	
	for(i=0;i<cnt;i++)
	{
	//	printf("%s",b[i]);
	fputs(b[i],fp);

	}
	printf("%d\n",cnt);
	fclose(fp);
*/
	fclose(fp1);	
}
