#include<stdio.h>
#include<unistd.h>
main()
{
	int a,b;
	printf("befor close\n");
	printf("enter a:");
	if(scanf("%d",&a)==1)
	printf("a=%d\n",a);
	else printf("failure\n");
	sleep(1);
	close(0);
	printf("after close\n");
	printf("enter b:");
	if(scanf("%d",&b)==1)
	printf("b=%d\n",b);
	else printf("failure\n");
	
}
