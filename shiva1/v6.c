#include<stdio.h>
int main(){
	short int x=55,y=65;
	printf("x=%hd y=%hd\n",x,y);
	printf("enter two integers:");
	scanf("%hd%hd",&x,&y);
	printf("x=%hd y=%hd",x,y);
	return 0;
}
