#include<stdio.h>
struct st1
{
	int a;
	float b;
};
struct st2
{
	int a;
	double b;
};
struct st3
{
	int a;
	double b;
	char c;
	double d;
};
main()
{
	struct st1 v1;
	struct st2 v2;
	struct st3 v3;
	printf("%lu %lu %lu\n",sizeof(v1),sizeof(v2),sizeof(v3));
	printf("%u %u %u\n",&v1,&v2,&v3);
	printf("%u %u %u\n",&v1.a,&v2.a,&v3.a);
	printf("%u %u %u\n",&v1.b,&v2.b,&v3.b);
	printf("%u %u \n",&v3.c,&v3.d);
}
