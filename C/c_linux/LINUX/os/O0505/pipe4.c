#include"header.h"
main()
{
	int p[2];
	pipe(p);
	if(fork())
	{
		close(0);
		dup(p[0]);
		close(p[1]);
		execlp("wc","wc",0);

	}
	else
	{
		close(1);
		dup(p[1]);
		close(p[0]);
		execlp("ls","ls",0);

	}
}
