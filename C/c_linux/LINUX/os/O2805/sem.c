#include<sys/sem.h>
#include<stdio.h>
int main(int argc,char **argv)
{
	int semval,index;
	int id;
	id=semget(1,3,IPC_CREAT|0666);
	printf("id=%d process %d\n",id,getpid());
	index=atoi(argv[1]);
	semval=semctl(id,index,GETVAL);
	printf("id=%d val %d\n",index,semval);
	

}
