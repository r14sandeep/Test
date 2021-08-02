#include<stdio.h>
main()
{
	long a[2][4]={01,11,21,31,41,51,61,71};
	printf("%ld\n",a[1][2]);
	printf("%ld %ld\n",*(a[1]+3),3[a[1]]);
	printf("%ld %ld %ld\n",*(*(a+1)+2),*(1[a]+2),3[1[a]]);


}
