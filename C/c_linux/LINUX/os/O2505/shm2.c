#include"header.h"
main()
{
	int id;
	char *ptr;
	id=shmget(1,20,IPC_CREAT|0666);
	ptr=shmat(id,NULL,0);
//	printf("memory at:%x\n",(int)ptr);
	ptr=calloc(1,20);
	strcpy(ptr,"vector");
//	printf("%s\n",ptr);
	shmdt(ptr);
//	while(1);
}
