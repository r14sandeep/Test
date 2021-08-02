#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char sentence[40];
int flag=0;
int search(char *temp)
{
	FILE *fp; 
	fp=fopen("dict.txt","r");
	char word[20];
	while(fscanf(fp,"%s",word)!=EOF)
	{
		if((strcmp(word,temp)==0)&&(strstr(sentence,temp)==NULL))
		{
			fclose(fp);
			return 0;
		}
/*		else
		if((strcmp(word,temp)==0)&&(strstr(sentence,temp)==NULL))
		{
			fclose(fp);
			return 0;
		}
*/	}
	fclose(fp);
	return 1;

}
int main()
{

	char string[20],*temp;
	int len,index,j=0;
	printf("enter a string:");
	gets(string);
	len=strlen(string);
///	while(1)
//	{
	while(j<len)
	{

		for(index=1;index<len;index++)
		{
			temp=calloc(1,40);
			strncpy(temp,string+j,index);
			int status;
			status=search(temp);	
			if(status==0)
			{
				
				strcat(sentence,temp);
				strcat(sentence," ");
				j+=strlen(temp);
				break;
			}
				free(temp);
				temp=NULL;
			
		}
		if(index==len)
			j++;
	}
//	flag=1;
	//strcat(sentence,'\n');
	puts(sentence);
/*	char w1[20],w2[20],temp2[20]="\0";
	int i;
	while(sscanf(sentence,"%s",w1)!=EOF)
	{
		strcpy(temp2,w1);
		sscanf(sentence+strlen(w1),"%s",w2);
		i=strcat(temp2,w2);
		if(i==0)
			


		search(temp2);
		
	if()
*/
///	j=0;
//	}
}
