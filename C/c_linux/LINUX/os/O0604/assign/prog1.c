#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	int res;
	if(fork()==0)
	{
		res=(atoi)(argv[1])+(atoi)(argv[2]);
		printf("%d\n",res);
		exit(res);

	}
	else
	{
		wait(&res);
		res>>=8;
		printf("sum is %d\n",res);
	}

}
