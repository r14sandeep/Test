#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
void parentcode(void);
void childcode(void);
void isr(void);
int pid[4];
main()
{
        pid[0]=getpid();
        if(pid[1]=fork())
        {
                if(pid[2]=fork())
                {
                        if(pid[3]=fork())
                                parentcode();
                        else
                                childcode();
                }
                else
                        childcode();
        }
        else
                childcode();
}
void childcode(void)
{
	int t;
	srand(getpid());
	printf("child:%d",getpid());
	t=rand()%10+1;
	printf("child %d,delay %dsec \n",getpid(),t);
	sleep(t);
	exit(0);
}
void parentcode(void)
{
	signal(SIGCHLD,isr);
	while(1);
}
void isr(void)
{
	wait(0);
}
