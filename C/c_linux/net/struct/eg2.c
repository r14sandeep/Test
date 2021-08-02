#include<stdio.h>
main()
{
	struct temp
	{
		char *n;
		int age;
	};
	struct emp e1={"vector",23};
	struct emp e2=e1;
	strupr(e2.n);
	printf("%s\n",e1.n);


}
