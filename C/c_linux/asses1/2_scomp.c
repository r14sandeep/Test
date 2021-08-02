#include<stdio.h>
main()
{
	int a,n,bit=7;
	printf("enter n");
	scanf("%d",&n);
	a=(~n)+1;
	while(bit>=0)
	{
		printf("%d",(a>>bit)&1);
		bit--;
	
}


}
