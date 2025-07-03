#include<stdio.h>
int main(){
	char ch;
	printf("enter the charecter:");
	scanf("%c",&ch);
	(ch>=65)&&(ch<=90)||(ch>=97)&&(ch<=122)?printf("entered alphabet\n"):printf("entered is not a alphabet\n");
	return 0;
}
