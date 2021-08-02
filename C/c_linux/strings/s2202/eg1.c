#include<stdio.h>
main()
{
	int a[][4]={{11,22},{33,44,55,66},{77,88}};
	printf("%u %u  ",*(a+1),a);
printf("%u\n",&a[1][1]);
printf("%d %d\n",a[1][1],*(a+1)[1]);
}
