//////search for a word in a file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char **argv)
{
	FILE *fp;
	int size,cnt=0,i;
	char *buf,*found;
	fp=fopen(argv[1],"r");
	fseek(fp,0,2);
	size=ftell(fp);
	rewind(fp);
	buf=calloc(1,size+1);
	fread(buf,size,1,fp);
	found=buf;
	//for(i=0;i<size;i++)
/*	while(fgets(buf,100,fp))
	{
		if(found=strstr(buf,argv[2]))
		{	

			cnt++;
			printf("%s\n",buf);
		}	
	}
*/
	while(found=strstr(found,argv[2]))
	{
		cnt++;
		printf("%s\n",argv[2]);
//		memmove(found,found+strlen())
		found++;
	}
	printf("found %d times\n",cnt);
	fclose(fp);

}
