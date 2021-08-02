#include<stdio.h>
void f(int n)
{


}

main()
{
	signal(SIALRM,f);
	alarm(4);
	printf("%d\n",getpid());
	while(1);




}
