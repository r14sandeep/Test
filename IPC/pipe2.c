#include"header.h"
int main()
{
	int p[2];
	pipe(p);
	int v=4;
	if(fork())
		execlp("wc","wc",NULL);
	else
		execlp("ls","ls",NULL);
		


}
