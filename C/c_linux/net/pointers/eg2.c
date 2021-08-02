#include<stdio.h>
main()
{
	int x=30,*y,*z;
	y=&x;
	z=y;
	*y++=*z++;
	x++;
	printf("x=%d y=%u z=%u %u\n",x,y,z,&x);



}
