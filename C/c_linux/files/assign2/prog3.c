#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *upper(char *,char *);
main(int argc,char **argv)
{
	FILE *fp;
	char *buf,*found;
	int size=0,i,j,k;
	fp=fopen(argv[1],"r");
	while(fgetc(fp)!=EOF)
		size++;
	fclose(fp);
	buf=calloc(1,size+1);
	fp=fopen(argv[1],"r");
	fread(buf,size,1,fp);
	fclose(fp);
	buf=upper(buf,argv[2]);	
	fp=fopen(argv[1],"w");
	for(i=0;i<size;i++)
		fputc(buf[i],fp);


	fclose(fp);
}
char *upper(char *buf,char *s1)
{
	char *found,*temp;;
	int i,j,k;
	found=buf;
	temp=s1;
	while(found=strstr(found,s1))
	{
		j=found-buf;
		k=strlen(s1)-1;
	/*	k=j;
		while(j<k+strlen(s1))
		{
			buf[j]=buf[j]-32;
			j++;
		}
	*/
///////code for making all the occurnses cap///////
	/*	for(i=j;i<(j+strlen(s1));i++)
			buf[i]=buf[i]-32;
*/		
///////code for reverse all the occurnses ///////

		for(i=j;i<(j+strlen(s1));i++)
		{
			buf[i]=s1[k--];
		}	
	found++;
	}
	return buf;
	//fclose(buf);
}
