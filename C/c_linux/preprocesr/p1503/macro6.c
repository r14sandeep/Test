#include<stdio.h>
#define A
#ifndef A
int main()
{
	#ifdef
	printf("hiiiiii\n");
	#else
	printf("hellllllooo\n");
	#endif
}
#else
int main()
{
	#ifdef B
	printf("vector\n");
	#else
	printf("india\n");
	#endif	
}
#endif
