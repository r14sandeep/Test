#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void f(int n)
{
	int i,j;
	printf("in isr...\n");
	for(i=0;i<1000000;i++)
	printf("out of isr\n");
}

main()
{
	struct sigaction v;
	v.sa_handler=f;
	v.sa_flags=0;
	//sigemptyset(&v.sa_mask);
	sigfillset(&v.sa_mask);
	sigaction(SIGINT,&v,NULL);

}

