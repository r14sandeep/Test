#include"header.h"
int main()
{
	int val;
	val=fork();
	if(val)
	{
		printf("in parent\n");
		printf("parent exiting\n");
		printf("ppid:%d,pid:%d\n",getppid(),getpid());
		exit(0);
	}
	else
	{	
		int res;
		printf("in child\n");
		printf("ppid:%d,pid:%d\n",getppid(),getpid());
		sleep(10);
		res=setsid();
		printf("res=%d\n",res);
		printf("ppid:%d,pid:%d\n",getppid(),getpid());
		close(0);
		close(1);
		close(2);
		sleep(30);
		
	}
}
