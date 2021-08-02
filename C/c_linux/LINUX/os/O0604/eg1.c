#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/resource.h>
void f(int );
struct v{
int v;
};
int main()
{
	struct v var;
	
	struct sigaction v;
	v.sa_handler=f;
	v.sa_flags=0;
	sigemptyset(&v.sa_mask);
//	sigaction(SIGALRM,&v,NULL);
	sigaction(SIGALRM,&v,NULL);
//	signal(14,f);
	alarm(10);
	printf("%d,%d\n",getpid(),var.v);
	while(1);
	return 0;
}
void f(int n)
{
	printf("alarm....%d\n",n);
	alarm(2);
	//signal(n,f);

}
