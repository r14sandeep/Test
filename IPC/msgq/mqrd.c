#include"header.h"
int main()
{
	int id;
	id=msgget(-1,IPC_CREAT|0600);
	if(id==-1)
	{
		perror("msgget");
		return;
	}
	printf("id:%d\n",id);


}
