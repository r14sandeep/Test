#include<stdio.h>
#include<sys/resource.h>
void f(void)
{
	char str[1000000];
	static int cnt=0;
	cnt++;
	printf("cnt=%d\n",cnt);
	if(cnt<15)
		f();
	printf("returning from f\n");

}
int main()
{
	struct rlimit v;
	if(getrlimit(RLIMIT_STACK,&v)==-1)
		perror("getrlimit");
	else
		printf("%u %u\n",v.rlim_cur,v.rlim_max);
	v.rlim_cur*=2;
		printf("%u %u\n",v.rlim_cur,v.rlim_max);
		setrlimit(RLIMIT_STACK,&v);
	f();



}
