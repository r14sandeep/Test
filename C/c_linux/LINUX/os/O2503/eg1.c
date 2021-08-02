#include<stdio.h>
void f(void)
{
	char str[1000000];
	static int cnt=0;
	cnt++;
	printf("cnt=%d\n",cnt);
	if(cnt<15)
		f();
	printf("returning from f\n");

}
int main()
{
	f();

}
