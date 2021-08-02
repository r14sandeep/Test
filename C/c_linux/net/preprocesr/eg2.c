#include<stdio.h>
#define SQR(x) x*x
main()
{
	float a=10,u=30,t=2,i;
	i=2*(a-u*t)/SQR(t);
	printf("%f\n",i);


}
