#include"header.h"
#include<sys/shm.h>
	char *ptr;
void parent(void)
{
	int v=65;
	int i;
	for(i=0;i<5;i++)
	{
		ptr[i]=i+65;
		sleep(1);
	}
	puts(ptr);
	sleep(5);
	puts(ptr);
	shmdt(ptr);
	exit(0);
}
void child(void)
{
	int i;
	for(i=0;i<5;i++)
	{
		ptr[i]=i+97;
		sleep(1);
	}
	exit(0);

}

main()
{
	int id;
	id=shmget(1,5,IPC_CREAT|0666);	
	ptr=shmat(id,NULL,0);
	if(fork())
		parent();
	else
		child();
	shmdt(ptr);
}
