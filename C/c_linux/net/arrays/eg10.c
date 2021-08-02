#include<stdio.h>
main()
{
	//  volatile
	 int x,a=3,p=9;
	x=++a,++a,a++;
	printf("%d %d\n",x,a);


}
