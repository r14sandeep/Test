#include<stdio.h>
struct  data
{
	int a;
	float b;

}v;
struct data fun(struct data v)
{
	printf("enter int:");	
	scanf("%d",&v.a);
	printf("enter float:");	
	scanf("%f",&v.b);
	return v;

}

main()
{
	v=fun(v);	
	printf("%d %f\n",v.a,v.b);
	printf("%d\n",sizeof(v));
	
}
