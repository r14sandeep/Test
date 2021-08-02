#include<stdio.h>
main()
{
	int n=123.5;
	float f=213;
	n=printf("n=%d\n",n);
	printf("%d\n",n);
	n=printf("%d",printf("f=%f\n",f));
	printf("%d\n",printf("n=%d\n"+2,n));
	printf("%d",10+2);
	printf("%d",printf("f=%f\n"+3,f));
	printf("f=%f\n"+3,f);
	printf("n=%d\n"+2,n);
	


}
