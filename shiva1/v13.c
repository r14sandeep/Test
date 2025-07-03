#include<stdio.h>
int main(){
	float v=1234.5;
	printf("v=%e %f\n",v,v);
	v=v*100;
	printf("v=%e %f\n",v,v);
	v=3.4;
	printf("v=%e %f\n",v,v);
        v=0.000567;
	printf("v=%e %f\n",v,v);
	return 0;
}
