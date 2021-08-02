#include<stdio.h>
#include<math.h>
f(int v)
{
	printf("%d\n",v);
}

main()
{
	int v;
	scanf("%d",&v);
	f(pow(v,2));
}
