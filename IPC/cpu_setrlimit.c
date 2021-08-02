#include<stdio.h>
#include<sys/resource.h>
int main()
{
	struct rlimit v;
	getrlimit(RLIMIT_CPU,&v);
	printf("%u,%u\n",v.rlim_cur,v.rlim_max);	
	v.rlim_cur=10;
	setrlimit(RLIMIT_CPU,&v);
	printf("%d\n",getpid());
	while(1);
	

}
