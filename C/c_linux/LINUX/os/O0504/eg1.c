#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void isr(int n)
{
	wait(0);

}
main()
{
	if(fork()==0)
	{
		printf("in child %d\n",getpid());
		sleep(10);
		exit(0);

	}
	else
	{
		printf("in parent %d\n",getpid());
		sleep(5);
		signal(SIGCHLD,isr);
		exit(0);

	}
}
