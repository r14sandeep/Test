////wap to i/p to ints test if one of them is +ve pow of other
#include<stdio.h>
main()
{
	int a,b,res=1;
	printf("enter a,b:");
	scanf("%d%d",&a,&b);
	if(a>b)
		a^=b^=a^=b;
	while(res<b)
		res=res*a;
	if(res==b)
		printf("a is pow of b\n");
	else
		printf("a is not pow of b\n");
}
