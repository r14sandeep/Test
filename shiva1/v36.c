#include<stdio.h>
int main(){
        char ch;
	puts("enter a charecter:");
        scanf("%c",&ch);
	printf("ch=%c\n",ch);
	ch^=32;
	printf("ch=%c\n",ch);
}
