#include"header.h"
int main()
{
	int val;
	val=fork();
	if(val)
	{
		printf("in parent\n");
//		execl("/bin/ls","ls",NULL);

//		execl("./sum","4",NULL);
		execl("/bin/ls","ls","-l","-i",NULL);
	}
	else
	{
		sleep(2);
		printf("in child\n");
		execl("/usr/bin/cal","cal",NULL);
	}

}
