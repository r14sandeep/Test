#include"header.h"
#include<unistd.h>
void f2(int n)
{
puts("f2 termination");
}
int f(int n)
{
//	printf("alarm %d,%d\n",n,cnt);
	int cnt=10;
	alarm(5);
	if(signal(SIGALRM,f2))
	{	puts("signal");
		return cnt;		
	}
	while(cnt)
	{	cnt++;puts("f");sleep(1);
	if(cnt==15)
		alarm(0);
	}
//	alarm(0);
	puts("time is ok");
	return cnt;

	
//	exit(1);
}

int main()
{
	int n;
//	n=f(2);
//	signal(SIGALRM,f);

	
//	if(alarm(2))
//	printf("n=%d %d\n",n,getpid());
//	printf("n=%d\n",n);
	n=f(10);
	printf("n=%d\n",n);
	puts("exit");
	return 0;
}
