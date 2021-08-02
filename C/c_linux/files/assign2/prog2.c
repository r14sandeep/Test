#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fp;
	char *buf;
	int size=0,i;
	fp=fopen(argv[1],"r");
	while(fgetc(fp)!=EOF)
		size++;
	fclose(fp);
	buf=calloc(1,size+1);
	fp=fopen(argv[1],"r");
	for(i=0;i<size;i++)
	{
		buf[i]=fgetc(fp);
		if((buf[0]>96)&&(buf[0]<123))
			buf[0]=buf[0]-32;
		if((buf[i]=='.'))
		{	buf[++i]=fgetc(fp);
			if(buf[i]=='\n')	
				buf[++i]=fgetc(fp);
			if((buf[i]>'a')&&(buf[i]<'z'))
				buf[i]=buf[i]-32;
				
		}
/*		else					
			if(buf[i]=='\n')
			{
				buf[++i]=fgetc(fp);
				buf[i]=buf[i]-32;

			}
*/
	}
	fclose(fp);
	fp=fopen(argv[1],"w");
	for(i=0;i<size;i++)
		fputc(buf[i],fp);
	fclose(fp);
	//fp=fopen(argv[1],"a");
	//fputs(_DATE_,fp);
//	fclose(fp);
		
	
	//fclose(buf);
}
