#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("file.txt","r");
	char s[100],*buf;
	fseek(fp,0,2);
	int size=ftell(fp);
	rewind(fp);
	buf=calloc(1,size+1);
	fread(buf,size,1,fp);
	puts(buf);
	fclose(fp);
	int v1,v2;
	char ch,word[10];
//	while(sscanf(buf,"%d%c%d",&v1,&ch,&v2)!=EOF)
	while(sscanf(buf,"%s",word)!=EOF)
	
	{
	//	puts(s);
	//	buf+=strlen(s)+1;
		puts(word);
	/*	switch(ch)
		{
			case '+':printf("%d\n",v1+v2);break;
			case '-':printf("%d\n",v1-v2);break;
			case '*':printf("%d\n",v1*v2);break;
		}
	*/	
	}

}
