#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp,*fp2;
	char buf[100],*temp1;
	int a,i,size;
	fp=fopen(argv[1],"r");
	fp2=fopen("temp","w");
	while(fgets(buf,100,fp)!=NULL)
	{
		a=strlen(buf);
	//	for(i=0;i<a;i++)
	//	{
			if(buf[1]=='+')	
			{
				buf[a]=buf[0]+buf[2];
				buf[a+1]='\0';
			}
			else 
			{	if(buf[1]=='-')
			{	buf[a]=buf[0]-buf[2];
				buf[a+1]='\0';}
			else if(buf[1]=='*')
			{	buf[a]=buf[0]*buf[2];
				buf[a+1]='\0';}
			else if(buf[1]=='/')
			{	buf[a]=buf[0]/buf[2];
				buf[a+1]='\0';}
			}
	//	}
		fputs(buf,fp2);	

	}
	fclose(fp2);
	fclose(fp);
	fp=fopen(argv[1],"w");
	fp2=fopen("temp","r");
	
	fseek(fp2,0,2);
	size=ftell(fp2);
	rewind(fp2);	
	temp1=calloc(1,size+1);
	fread(temp1,size,1,fp);
	fclose(fp2);
	fputs(temp1,fp);
	fclose(fp);


}







