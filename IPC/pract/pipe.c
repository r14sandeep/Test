#include<stdio.h>
int v=4;
int main()
{
//	v++;
	if(fork()==0)
	{
		puts("inchild");
		v++;
		printf("ch:%d\n",v);
		exit(0);
	}
	else
	{
		puts("inparent");
		v++;
		printf("p:%d\n",v);
		wait(0);
	}

}
