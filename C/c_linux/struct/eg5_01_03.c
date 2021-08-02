#include<stdio.h>
struct st1
{
	int a;
	char c;
	double b;
	double d;
};
struct st2
{
	
	double d1;
	char c1;
	short int s1;
	float f1;
	double d2;
	char c2;
	int i2;
	
};
main()
{
	struct st1 v1;
	struct st2 v2;
	printf("%lu %lu\n",sizeof(v1),sizeof(v2));
	
}
