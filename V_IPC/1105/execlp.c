#include"header.h"
int main()
{
	int val;
	val=fork();
	if(val)
	{
		printf("in parent\n");
		execl("/bin/ls","ls",NULL);
//		execlp("./ls","./ls",NULL);
//		execlp("./sum","2","3",NULL);
	}
	else
	{
		sleep(2);
		printf("in child\n");
		execlp("cal","cal",NULL);
	}

}
