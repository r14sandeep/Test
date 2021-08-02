#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
main()
{
	struct rlimit v;
	getrlimit(RLIMIT_CPU,&v);
	v.rlim_cur=5;
	v.rlim_max=10;
	setrlimit(RLIMIT_CPU,&v);
	printf("%d\n",getpid());
	while(1);


}
