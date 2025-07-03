#include<stdio.h>
int main(){
	int a=20,b=30;
	printf("a=%d b=%d\n",a,b);
	a^=b^=a^=b;
	printf("a=%d b=%d\n",a,b);
	return 0;
}
