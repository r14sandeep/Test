#include"header.h"
int main()
{
	int id;
	char *ptr;
	id=shmget(1,100,IPC_CREAT|0666);
	ptr=shmat(id,NULL,0);
	printf("%s\n",ptr);
	shmdt(ptr);
}
