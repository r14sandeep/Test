//////wap to i/p two ints store in a,b and calculate a^b;
#include<stdio.h>
main()
{
	int a,b,res=1,i;
	printf("enter a,b:");
	scanf("%d%d",&a,&b);
	for(i=0;i<b;i++)
		res=res*a;
	printf("%d\n",res);


}
