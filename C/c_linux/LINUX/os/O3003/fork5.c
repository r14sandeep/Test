#include<stdio.h>
main()
{
	printf("before %d\n",getpid());
	fork();
	printf("after1 %d\n",getpid());
	fork();
	printf("after2 %d\n",getpid());

}
