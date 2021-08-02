#include<stdio.h>
main()
{
	char c='A',c1;
	int i=20,i1;
	double d=32.5,d1;
	char *cp=&c;
	c1=(*cp);
	cp=&i;
	i1=(*(int*)cp);
	cp=&d;
	d1=(*(double*)cp);
	printf("c1=%c,i1=%d.d1=%lf\n",c1,i1,d1);


}
