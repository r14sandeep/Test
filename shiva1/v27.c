#include<stdio.h>
#include<ctype.h>
int main(){
	char ch;
	puts("enter the charecter:");
        ch=getchar();
	isdigit(ch)?printf("entered is digit"):isupper(ch)?printf("entered is uppercase letter"):islower(ch)?printf("entered is lowwer case letter"):printf("entered is spl charecter");
	return 0;
}
