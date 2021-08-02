#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp1,*fp2;
	fp1=fopen("test.txt","r");
	fp2=fopen("temp.txt","w");
	char *buf,buff[100];
	int cnt=1,line,size,nlines=0;
	while(fgets(buff,100,fp1))
		nlines++;
	printf("enter line to be deleted from 1 to %d only:",nlines);
	scanf("%d",&line);
	rewind(fp1);
	if((line<nlines)&&(line>0))
	{
		while(fgets(buff,100,fp1))
		{
			if(cnt!=line)
				fwrite(buff,strlen(buff),1,fp2);
			cnt++;
		}
		fclose(fp2);
		fclose(fp1);
		fp2=fopen("temp.txt","r");
		fp1=fopen("test.txt","w");
		fseek(fp2,0,2);
		size=ftell(fp2);
		buf=calloc(1,size+1);
		rewind(fp2);
		fread(buf,size,1,fp2);
		fwrite(buf,size,1,fp1);
		fclose(fp2);
		fclose(fp1);
		printf("done\n");	
	}
	else
		printf("invalid line\n");

}
