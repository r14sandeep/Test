//////wap to search a string in file and make all the occurances upper case....

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//char *upper(char *,char *);
main(int argc,char **argv)
{
	FILE *fp;
	char *buf,*found,*s;
	int size=0,i,j,k;
	fp=fopen(argv[1],"r");
	while(fgetc(fp)!=EOF)
		size++;
	buf=calloc(1,size+1);
	fread(buf,size,1,fp);
	fclose(fp);
	s=argv[2];
	found=buf;
	while(fgets(buf,100,fp)!=NULL)
	{
		if(found=strstr(found,s))
		{
			j=found-buf;
			k=j;
			while(j<(k+strlen(s)))
			{
				buf[j]=buf[j]-32;
				j++;

			}

		}
	}
	fp=fopen(argv[1],"w");
	for(i=0;i<size;i++)
		fputc(buf[i],fp);
	fclose(fp);
}
/*char *upper(char *buf,char *s1)
{
	char *found;
	int i,j,k;
	found=buf;
	while(found=strstr(found,s1))
	{
		j=found-buf;
		k=j;
		while(j<k+strlen(s1))
		{
			buf[j]=buf[j]-32;
			j++;
		}
	}
	return buf;
	//fclose(buf);
}*/
