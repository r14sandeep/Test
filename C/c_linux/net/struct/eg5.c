#include<stdio.h>
main()
{
	enum days
	{mon=-1,tue,wed=6,thu,fri,sat};
	printf("%d,%d,%d,%d,%d,%d\n",++mon,tue,wed,thu,fri,sat);
	//printf("%d\n",sizeof(enum days));

}
///////error in printf,invalid increment
