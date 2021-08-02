#include"header.h"
int main()
{
	FILE *read_fp;
	char buff[BUFSIZ+1];
	int char_read;
	bzero(buff,sizeof(buff));
//	read_fp=popen("uname -a","r");
	read_fp=popen("od -c","r");
	if(read_fp!=NULL)
	{
		char_read=fread(buff,sizeof(char),BUFSIZ,read_fp);
		if(char_read>0)
			printf("o/p:%s\n",buff);
		pclose(read_fp);
		exit(EXIT_SUCCESS);

	}

}
