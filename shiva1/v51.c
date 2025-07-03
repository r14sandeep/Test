#include<stdio.h>
#include<ctype.h>
int main(){
	char ch;
	scanf("%c",&ch);
	isupper(ch)?printf("%c\n",ch-=32):islower(ch)?printf("%c\n",ch+=32):printf("wrong input");
	return 0;
}
