#include<stdio.h>
int main(){
	int a=-20,b=0;
	b=a>>1;
	printf("a=%d b=%d\n",a,b);
	a=20,b=0;
        b=a>>1;
	printf("a=%d b=%d\n",a,b);
	a=-15,b=0;
	b=a>>1;
	printf("a=%d b=%d\n",a,b);
        a=15,b=0;
	b=a>>1;
	printf("a=%d b=%d\n",a,b);
	return 0;
}
