#include<stdio.h>
#include<ctype.h>
int main(){
	char ch;
	scanf("%c",&ch);
isupper(ch)?ch=ch+32:islower(ch)?ch=ch-32:printf("wrong input\n");
printf("%c\n",ch);
	return 0;
}
