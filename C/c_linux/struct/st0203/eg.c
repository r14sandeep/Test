#include<stdio.h>
void input(int **q)
{
	printf("%u\n",**q);
}
main()
{
	int v=10,*p;
	printf("%u\n",&v);
	p=&v;
	printf("%u\n",&p);
	input(&p);


}
