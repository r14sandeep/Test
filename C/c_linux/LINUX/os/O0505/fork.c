#include<stdio.h>
#include<unistd.h>
void fun()
{
	printf("fun\n");
	sleep(4);
}
int main()
{
	int v;
	for(v=0;v<3;v++)
		if(fork())
			fun();
		else
			printf("child\n");
}
