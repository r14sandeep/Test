#include"header.h"
int main(int argc,char **argv,char **env)
//int main()
{
	int val;
//	char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
	val=fork();
	if(val)
	{
		printf("in parent\n");
		execle("/bin/ls","ls","-l",NULL,env);
	}
	else
	{
		sleep(2);
		printf("in child\n");
//		execl("/usr/bin/cal","cal",NULL);
	}

}
