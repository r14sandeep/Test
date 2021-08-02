#include<stdio.h>
main()
{
	int a,b;
	printf("before closer\n");
	printf("enter a:");
	scanf("%d",&a);
	printf("a=%d\n",a);
//	sleep(1);
	close(1);
	printf("before closer\n");
	printf("enter b:");
	scanf("%d",&b);
	printf("b=%d\n",b);
	
}
