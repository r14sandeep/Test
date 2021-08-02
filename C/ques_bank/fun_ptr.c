#include<stdio.h>
int fun(int val)
{
	val+=1;
	return val;
//	printf("in fun\n");

}
int main()
{
	int (*ptr)(int);
	int a;
	ptr=fun;
	a=ptr(2);
	printf("a=%d\n",a);


}
