#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch;
	int cnt=1;
	
	fp=fopen(argv[1],"r");
	if(atoi(argv[2])==1)
	{
		while((ch=fgetc(fp))!='\n')
			printf("%c",ch);
		printf("\n");
		return;
	}
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch=='\n')
		{	cnt++;	}	
			
		if(cnt==atoi(argv[2]))
		{
			while((ch=fgetc(fp))!='\n')
			{
			printf("%c",ch);
			//return;
			}
			printf("\n");
			return;
		}
	
	}


}
