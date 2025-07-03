#include<stdio.h>
int main(){
	float length,result;
	scanf("%f",&length);
	result=length*2.54;
	printf("%.0f inch= %.2f cm\n",length,result);
        result=length*0.39;
	printf("%.0f cm= %.2f inch\n",length,result);
        return 0;
}
