#include"header.h"
main()
{
	int id;
	char *ptr;
	id=shmget(1,20,IPC_CREAT|0666);
	ptr=shmat(id,NULL,0);
//	printf("mem at:%d\n",ptr);
	ptr=calloc(1,20);
	printf("%s\n",ptr);
	shmdt(ptr);
}
