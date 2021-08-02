#include"header.h"
main()
{
	signal(SIGINT,SIG_IGN);
	printf("%d\n",getpid());
	while(1);


}
