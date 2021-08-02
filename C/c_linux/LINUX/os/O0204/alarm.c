#include"header.h"
volatile int flag=0;
void f1(int val)
{
	puts("alarm");
	flag=1;

}
int fun(int n)
{
	int v=12;
	alarm(6);
	if(signal(SIGALRM,f1)!=NULL)
	{
		puts("signal");
		return v;
	}
	while(1)
	{
		if(flag==1)
			return v;
	}


}

int main()
{
	int n;
//	alarm(4);
//	signal(SIGALRM,fun);
	n=fun(3);	
	printf("n=%d\n",n);


}
