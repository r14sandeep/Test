#include"header.h"
main()
{
	signal(SIGHUP,SIG_IGN);
	printf("%d\n",getpid());
	while(1);

}
