#include<stdio.h>
int main(){
	int a,b,c;
	a=1,b=2,c=3;
	a=a?b:c;
	c=-b?a:c;
	printf("%d %d\n",a,c);
}
