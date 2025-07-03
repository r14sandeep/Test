#include<stdio.h>
int main(){
	int i=56.7;
	float f=12;
	printf("i=%d f=%f\n",i,f);
	i=f;
	printf("i=%d f=%f\n",i,f);
	i=i*20;
	f=i;
	printf("i=%d f=%f\n",i,f);
	return 0;
}
