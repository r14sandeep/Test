#include"header.h"
void f(int n)
{
	static int cnt;
	cnt++;
	printf("cnt=%d\n",cnt);
	printf("in isr due to %d \n",n);
	if(cnt==4)
		signal(n,SIG_DFL);
}
main()
{
	signal(SIGINT,f);
	printf("%d\n",getpid());
	while(1);

}
