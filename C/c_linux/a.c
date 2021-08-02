#include<stdio.h>
main()
{
	int i=10;
	int *p=&i;
	*p++;
	printf("%d\n",i);

}
