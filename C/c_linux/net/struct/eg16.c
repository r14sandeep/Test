#include<stdio.h>
main()
{
	struct bitfield
	{
		
		unsigned a:3;
		char b;
		unsigned c:5;
		int d;

	}bit;
	printf("%d\n",sizeof(bit));


}
