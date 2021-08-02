#include"header.h"
void fun(int n)
{

printf("%d\n",n);
alarm(2);
}
int main()

{
	signal(SIGALRM,fun);
	alarm(4);
	printf("main\n");
	while(1);


}
