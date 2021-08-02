#include"header.h"
int main()
{
	int val;
	val=fork();
	char *arg[]={"./sum",NULL};
	if(val)
	{
		printf("in parent\n");
//		execv("./sum",NULL);
		execv("./sum",arg);
	}
	else
	{
		sleep(2);
		printf("in child\n");
//		execv("ls","ls",NULL);
	}

}
