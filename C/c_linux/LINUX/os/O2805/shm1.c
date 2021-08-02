#include"header.h"
int id;
void parent(void)
{
	char *ptr;
	ptr=shmat(id,NULL,0);
	printf();

}

main()
{
	id=shmget(1,26,IPC_CREAT|0666);	
	if(fork())
		parent();
	else
		child();

}
