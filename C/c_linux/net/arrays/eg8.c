#include<stdio.h>
#include<math.h>
double myfn(double d)
{
	d=1;
	return d;

}
main()
{
	double (*a[3])(double);
	a[0]=exp;
	a[1]=sqrt;
	a[2]=myfn;
	printf("%lf\n",(*a)((*a[2])((**(a+)(4)))));
}
