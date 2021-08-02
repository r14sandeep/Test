//i/p two ints a,b and test if one of them is +ve power of other
#include<stdio.h>
main()
{
	int a,b,i,r=1;
loop:	printf("enter a,b");
	scanf("%d%d",&a,&b);
	if(a==b)
	{
		printf("exit\n");
		return 0;
	}
	if((a<0)||(b<0))
	{	printf("i/p again\n");
		goto loop;
	}
	if(a>b)
	{	a^=b^=a^=b;
		printf("a=%d b=%d\n",a,b);
	}

while(r<b)
	r=r*a;
//for(r=1;r<b;r*=a)
//{}

if(r==b)
	printf("a is power of b\n");
else printf("a is not the power of b\n");

}
