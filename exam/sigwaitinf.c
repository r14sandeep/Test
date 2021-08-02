#include<stdio.h>
#include<signal.h>
void fun(int n)
{
	printf("in fun\n");
//	signal(SIGINT,SIG_DFL);


}
int main()
{
	struct timespec *var;
	int v;
	const sigset_t *p;
	siginfo_t *q;
	signal(SIGINT,SIG_DFL);
//	signal(SIGSEGV,SIG_DFL);
//	alarm(5);
	printf("hello\n");
//	var->tv_sec=100;

//	while(1)
//	{
//		printf("****\n");
		v=sigwaitinfo(p,q);
	//	v=sigtimedwait(p,q,var);
//	}
//	printf("%s %s\n",p,q);
//i	puts(p);
	
	printf("%d\n",v);
	printf("hello v\n");
//	while(1);
//	sleep(2);


}
