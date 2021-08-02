#include<stdio.h>
#define big(a,b,c) (a>b)?\
((a>c)?printf("a = %d\n",a):printf("c=%d\n",c)):((b>c)?printf("b=%d\n",b):printf("c=%d\n",c))
int main()
{
	int a=10,b=1,c=12;
	big(10,23,15);
return 0;


}
