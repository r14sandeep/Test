#include<stdio.h>
main()
{
	struct bitfield
	{
		signed int a:3;
		unsigned int b:3;
		unsigned int c:1;
		

	};
	struct bitfield bit1={2,14,13};
	printf("%d\n",sizeof(bit1));


}
