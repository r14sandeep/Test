#include<stdio.h>
#include<ctype.h>
int main(){
	char ch;
	puts("enter a charecter:");
	ch=getchar();
	isdigit(ch)?printf("entered is digit\n"):0;
	isupper(ch)?printf("entered is uppercase\n"):0;
	islower(ch)?printf("entered is lowercase\n"):0;
	!(isdigit(ch)||isupper(ch)||islower(ch))?printf("spl charecter\n"):0;
	return 0;
	}
