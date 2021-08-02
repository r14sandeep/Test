#include<stdio.h>
#include<sys/resource.h>
main()
{
	struct rlimit v;
	getrlimit(RLIMIT_CPU,&v);
	printf("%u %u\n",v.rlim_cur,v.rlim_max);
	v.rlim_cur=10;
	printf("%u %u\n",v.rlim_cur,v.rlim_max);
	setrlimit(RLIMIT_CPU,&v);
	printf("process:%d\n",getpid());
	while(1);
	


}
