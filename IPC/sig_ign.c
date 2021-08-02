#include"header.h"
void fun(int n)
{
	static int c;
	printf("in fun\n");
	c++;
	if(c==3)
		signal(n,SIG_DFL);

}
int main()
{

	printf("hello\n");
//	sleep(10);
//	signal(SIGINT,SIG_IGN);
//	while(1);
	signal(2,fun);
	printf("parent\n");	
	while(1);


}
