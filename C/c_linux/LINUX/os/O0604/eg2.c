#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/resource.h>
void f(int );
main()
{
	struct sigaction v;
	v.sa_handler=f;
	v.sa_flags=SA_RESETHAND;
	sigemptyset(&v.sa_mask);
	sigaction(SIGALRM,&v,NULL);
	alarm(2);
	printf("%d\n",getpid());
	while(1);
}
void f(int n)
{
	printf("alarm\n");
	alarm(2);

}
