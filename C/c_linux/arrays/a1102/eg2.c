#include<stdio.h>
main()
{
	int a[]={11,22,33,44,55,66,77,88};
	int *p,i;
	p=a+4;
	p[-2]=p[1]+p[-3];
	++*p;
	*p++;
	p[2]=p[-2]+p[-3];
	for(i=0;i<8;i++)
		printf("%d ",a[i]);


}
