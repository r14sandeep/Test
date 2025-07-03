#include<stdio.h>
//#define PI=3.14;
int main(){
	int rad;
	float area,PI=3.14;
	scanf("%d",&rad);
	if(rad>=0){
		area=(PI*rad*rad)/2;
		printf("area of semi-cricle:%.3f\n",area);
	}else{
		printf("invalid input\n");
	}
	return 0;
}
