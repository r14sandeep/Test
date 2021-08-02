#include"header.h"
main()
{
	printf("%d\n",getpid());
	sleep(10);
	signal(SIGINT,SIG_IGN);
	printf("%d\n",getpid());
	while(1);	

}
