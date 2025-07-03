#include<stdio.h>
int main(){
	char ch;
	puts("enter the charecter:");
	ch=getchar();
	(ch>=48)&&(ch<=57)?printf("entered is digit\n"):(ch>=65)&&(ch<=90)?printf("entered id uppercase alphabet\n"):(ch>=97)&&(ch<=122)?printf("entered is lowercase alphabet\n"):printf("entered is spl charecter\n");
	return 0;
}
