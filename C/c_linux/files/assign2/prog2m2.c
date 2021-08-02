#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fp,*fp2;
	char buf[100];
	int size=0,i=0;
	fp=fopen(argv[1],"r");
//	fseek(fp,0,2);
//	size=ftell(fp);
//	buf=calloc(1,size+1);
	fp2=fopen("temp","a");
	while(fgets(buf,100,fp)!=NULL)
	{
		i=0;
		/*while((buf[i]==' ')||(buf[i]=='\t'))
			i++;
		*/
		for(i=0;buf[i];i++)
		{	if(buf[i]=='.')
			{	i++;
				if((buf[i]>'a')&&(buf[i]<'z'))
					buf[i]=buf[i]-32;
			}
		//if((buf[i]>'a')&&(buf[i]<'z'))
		//	buf[i]=buf[i]-32;

		}
		fputs(buf,fp2);



//		if((buf[0]>96)&&(buf[0]<124))
//			buf[0]=buf[0]-32;
//		fputs(buf,fp2);
	}
	
	fclose(fp);
	fclose(fp2);
}
