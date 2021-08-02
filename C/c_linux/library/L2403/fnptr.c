#include<stdio.h>
void f()
{
	printf("in f\n");
}

main()
{	int v=5;
	void (*p)(void);
	p=f;
	(*p)();//call to f indirectly



}
