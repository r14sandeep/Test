#include<stdio.h>
main()
{
	int *i,j=22;
	printf("j addr=%u\t",&j);
	i=&j;
	printf("%u\t",i);
	printf("%u\n",&i);


}
