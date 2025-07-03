#include<stdio.h>
int main(){
	char var='2';
	printf("%c..%d\n",var,var);
	var=var*2;
	printf("var=%c..%d\n",var,var);
	var=var*2;
	printf("var=%c..%d\n",var,var);
	var='?';
	printf("%c",var);
	return 0;
}
