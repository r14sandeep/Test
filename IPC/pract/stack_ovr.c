#include<stdio.h>
void fun()
{
	char str[1000000];
	static int cnt=0;
	printf("cnt=%d\n",cnt);
	cnt++;
	if(cnt<15)
		fun();
	printf("return\n");		
}
int main()
{
	fun();

}
