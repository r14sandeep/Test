#include<stdio.h>
struct tag1
{
	int a;
	float b;

};
struct tag2
{
	double a;
	char b[8];
};
int main()
{
	//printf("%lu\n",sizeof(struct));//not valid,strcut name should declare
	printf("%lu\n",sizeof(struct tag2));





}
