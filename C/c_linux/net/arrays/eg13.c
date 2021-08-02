#include<stdio.h>
main()
{
	static double *p,*q,*r,*s,t=5.0;
	double **a[]={&p,&q,&r,&s};
	int i;
	*p=*q=*r=*s=t;
	for(i=0;i<4;i++)
		printf("%.0f ",**a[i]);



}
