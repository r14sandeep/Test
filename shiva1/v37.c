#include<stdio.h>
#include<ctype.h>
int main(){
	char ch;
	puts("enter the cahrecter:");
	scanf("%c",&ch);
	isupper(ch)?ch+=32:islower(ch)?ch-=32:printf("enterred is not a alphabet");
	printf("ch=%c\n",ch);
	return 0;
}
