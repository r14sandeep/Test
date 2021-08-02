#include"header.h"
main()
{
	int p[2];
	pipe(p);
	if(fork())
		execlp("wc","wc",0);
	else
		execlp("ls","ls",0);


}
