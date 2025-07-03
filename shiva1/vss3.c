#include<stdio.h>
int main(){
	float temp;
	float result;
	scanf("%f",&temp);
       // result=(temp*9/5)+32;
        result=((temp-32)*5/9);
	printf("%.2f F=%.2f C\n",temp,result);
        result=(temp*9/5)+32;
	//result=((temp-32)*5/9);
	printf("%.2f C=%.2f F\n",temp,result);
	return 0;
}
