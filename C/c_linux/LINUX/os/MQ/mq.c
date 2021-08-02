#include"header.h"
main()
{
	int id;
	id=msgget(2,IPC_CREAT|0600);
	if(id==-1)
	{
		perror("msgget");
		return;
	}
	printf("id=%d in process %d\n",id,getpid());

}
