#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
main()
{
	//if(fork()==0) exit(0);
	//if(fork()==0) exit(0);
	//if(fork()==0) exit(0);
fork();
fork();
fork();
	
if(wait(0))
		printf("child\n");

}
