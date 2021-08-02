#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//comment//
int main()
{
/*commentadfsgsdfgsdfgsdfgdfsg*/
	FILE *fp1,*fp2;
	fp2=fopen("temp.txt","w");
	fp1=fopen("preproc.txt","r");
	char *buff;
	int size;
	fseek(fp1,0,2);
	size=ftell(fp1);
	rewind(fp1);
	buff=calloc(1,size+1);
	fread(buff,size,1,fp1);
/*	puts(buff);*/
	char *found,*temp;
	int len;
	found=buff;
		puts(found);				
/*	puts(found);*/
	while((found=strstr(found,"//"))||((found=strstr(found,"/*"))))
	{
		temp=found;
		puts(found);				
		found++;
//		printf("1\n");
		while((found=strstr(found,"//"))||((found=strstr(found,"*/"))))
		{
			len=size-(int )(found-temp);
		printf("size:%d,%d\n",size,len);		
			memmove(temp,found+1,len);
//		printf("2\n");
		printf("temp:%u,found:%u\n",temp,found);
		printf("%d\n",found-temp);		
		puts(found);
//		puts(temp);
			found++;
			break;

		}
	}

	puts(buff);
	
}
