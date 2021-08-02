#include<stdio.h>
#include<unistd.h>
main()
{
	int a,b;
	printf("befor close\n");
	printf("enter a:");
	scanf("%d",&a);
	printf("a=%d\n",a);
	sleep(1);
	close(0);
	printf("after close\n");
	printf("enter b:");
	scanf("%d",&b);
	printf("b=%d\n",b);
	
}
