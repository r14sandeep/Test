#include<stdio.h>
struct test
{
	int val;
	void (*ptr)(void);
};
void fun()
{
	puts("in fun");

}
int main()
{
	struct test v;
	v.ptr=fun;
	v.ptr();


}
