#include<stdio.h>
char f2(void);
char f1(void){
	char ch;
	printf("%c\n",ch=72);
	printf("%c\n",ch=73);
	f2();
}
int main(){
	char ch=83;
	printf("%c\n",ch);
        f1();
	printf("\n");
	printf("%c\n%c\n%c\n%c\n%c\n",ch=75,ch=73,ch=82,ch=65,ch=78);
}char f2(void){
	char ch;
	printf("%c\n",ch=86);
        printf("%c\n",ch=65);
}
