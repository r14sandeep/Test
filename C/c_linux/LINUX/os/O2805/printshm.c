#include"header.h"
#include<sys/shm.h>
main()
{
	int id;
	char *ptr;
	id=shmget(1,26,IPC_CREAT|0666);
	ptr=shmat(id,NULL,0);
	while(1)
	{
		printf("%c",ptr);
	}


}
