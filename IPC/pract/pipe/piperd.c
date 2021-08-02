#include"header.h"
int main()
{
	int p[2];
	char buf[10],rdbuf[10];
	pipe(p);
	if(fork()==0)
	{
		gets(buf);
		while(strcmp(buf,"quit")!=0)
		{
			write(p[1],buf,strlen(buf)+1);
			gets(buf);
		}

	}
	else
	{
//		while(strcmp(rdbuf,"quit")!=0)
//		{
			sleep(4);
			read(p[0],rdbuf,10);
			puts(rdbuf);
//		}
	}

}
