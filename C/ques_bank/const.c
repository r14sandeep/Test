#include<stdio.h>
int main()
{
//const *int a;
//const *int b=10;
	const int x=5;
//	x=10;
	int *p=&x;
	*p=10;
	printf("main %d\n",x);

}

