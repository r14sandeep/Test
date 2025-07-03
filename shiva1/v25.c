//W.A.P to test the category of suplied charecter
#include<stdio.h>
int main(){
	char ch;
	printf("enter a charecter:");
	scanf("%c",&ch);
        (ch>=48)&&(ch<=57)?printf("entered is numeric value\n"):0;
	(ch>=65)&&(ch<=90)?printf("entered is uppercase letter\n"):0;
	(ch>=97)&&(ch<=122)?printf("entered is lowwercase letter\n"):0;
	(ch>=0)&&(ch<=47)||(ch>=58)&&(ch<=64)||(ch>=91)&&(ch<=96)||(ch>=123)&&(ch<=127)?printf("entered is spl charecter\n"):0;
	return 0;
}
