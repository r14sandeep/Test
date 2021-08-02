#include<stdio.h>
main()
{
	int a[2][3]={5,10,15,20,25,30};
	int (*p)[2][3]=&a;
	printf("%d\n",***p);
	printf("%d\n",***(p+1));
	printf("%d\n",**(*p+1));
	printf("%d\n",**(*p+1));
	printf("%d\n",*(*(*p+1)+2));


}
