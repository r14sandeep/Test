#include"header.h"
int main()
{
	FILE *write_fp;
	char buff[BUFSIZ+1];
	int char_read;
	bzero(buff,sizeof(buff));
	write_fp=popen("od -c popen.c","w");
	if(write_fp!=NULL)
	{
//		char_read=fread(buff,sizeof(char),BUFSIZ,read_fp);
		fwrite(buff,sizeof(char),strlen(buff),write_fp);
		pclose(write_fp);
		exit(EXIT_SUCCESS);

	}

}
