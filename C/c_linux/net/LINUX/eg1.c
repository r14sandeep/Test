#include<stdio.h>
main()
{
	int i,cnt=0;
	for(i=0;i<4;i++)
		fork();
	printf("%d\n",getpid());


}
