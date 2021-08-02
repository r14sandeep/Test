#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch,buf[100];
	int cnt=0;
	fp=fopen(argv[1],"r");	
//	fseek(fp,0,2);
//	size=ftell(fp);
	//buf=calloc(1,size+1);

	while(fgets(buf,100,fp))
	{
		cnt++;
		if(cnt==atoi(argv[2]))
		{
			//printf("%s",buf);
			puts(buf);
		}

	}
fclose(fp);
}
