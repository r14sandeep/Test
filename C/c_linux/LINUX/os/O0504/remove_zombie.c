#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include<signal.h>
void isr(int);
main()
{
	if(fork()==0)
	{
		int t;
		srand(getpid());
		t=rand()%10+1;
		printf("child:%d parent:%d\n",getpid(),getppid());
		printf("delaying for %d sec\n",t);
		sleep(t);
		printf("child:%d parent:%d\n",getpid(),getppid());
		printf("exiting\n");
		exit(1);
	}
	else
	{
		signal(SIGCHLD,isr);
		printf("in parent %d",getpid());
		//while(1);
	}
	
}
void isr(int n)
{

	wait(0);
}
