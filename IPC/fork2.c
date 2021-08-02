#include"header.h"
int i=1;
int main()
{
	i++;
	printf("%d\n",i);
	if(fork()==0)
	{
		sleep(1);
		printf("in child:%d\n",i);
		sleep(1);
		i++;
		printf("in child:%d\n",i);
		sleep(10);
		exit(0);	

	}
	else
	{
		printf("in parent:%d\n",i);
		sleep(4);
		printf("in parent:%d\n",i);
		exit(0);
	}

}
