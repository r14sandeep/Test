#include<stdio.h>
void fun2();
int main()
{
	void fun1();
//	fun1();
	//fun2();

}
void fun2()
{
	fun1();
	puts("in fun2");
}
void fun1()
{
	puts("in fun1");
}
