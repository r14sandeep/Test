#include<stdio.h>
int main()
{
	int a=1;
	int b=2;
	if(&a>&b)
		puts("up");
	else
		puts("down");

}
