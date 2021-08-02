#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main(int argc,char **argv)
{
	FILE *fp1,*fp2,*fp3;
	char ch,*buf=0;
	char cnt=0;
	int size=0;
	fp1=fopen(argv[1],"r");
	fp2=fopen("temp","a");
	//////////copying the file 1 data into temp until the line no asked
	while(cnt<((atoi)(argv[2])-1))
	{
		ch=fgetc(fp1);
		fputc(ch,fp2);
		if(ch=='\n')
			cnt++;
	

	}
	

//////copying file 2 to temp file 
	fp3=fopen(argv[3],"r");
	
/*	while((ch=fgetc(fp3))!=EOF)
	{	
		fputc(ch,fp2);
	}*/
	fseek(fp3,0,2);
	size=ftell(fp3);
	buf=calloc(1,size+1);
	rewind(fp3);
	fread(buf,size,1,fp3);
	fputs(buf,fp2);
	fclose(fp3);
//////////appending remaining data of file 1 to temp


	while((ch=fgetc(fp1))!=EOF)
	{
		fputc(ch,fp2);

	}
	fclose(fp1);
	fclose(fp2);
	////////copy temp file to file1/////////////
	fp1=fopen(argv[1],"w");
	fp2=fopen("temp","r");
	fseek(fp2,0,2);
	size=ftell(fp2);
	rewind(fp2);
	buf=calloc(1,size+1);
	fread(buf,size,1,fp2);

	fputs(buf,fp1);
	fclose(fp1);
	
	fclose(fp2);
	

}
