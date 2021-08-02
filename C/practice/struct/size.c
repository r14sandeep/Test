#include<stdio.h>
struct Node
{
	int a:3;
	char b:2;
	float f;
	static int d;
//	char c[5]:15;

}S;
int main()
{
	
	printf("%d\n",sizeof(S));
	S.a=2;
	S.b=1;
	printf("%d,%d\n",(S.a),(S.b));
	
















}
