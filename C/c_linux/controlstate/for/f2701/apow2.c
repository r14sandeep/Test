////wap to i/p an int and test it is pow of 2 or not
#include<stdio.h>
main()
{
	int a,b,c;
	printf("enter a:");
	scanf("%d",&a);
	while(a>0)
	{
		b=a%2;
		a=a/2;
		if(a==1)
		{
			printf("a is pow of 2\n");
			return;
		}
		if(b>0)
		{
			printf("a is not pow of 2\n");
			return;
			

		}
	}

}
