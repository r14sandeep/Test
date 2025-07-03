#include<stdio.h>
int main(){
	unsigned short int var=0;
	printf("var=%u\n",var);    printf("var=%hu\n",var);
        --var;
	printf("var=%u\n",var);    printf("var=%hu\n",var);
	return 0;
}
