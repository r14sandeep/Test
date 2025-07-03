#include<stdio.h>
int main(){ int result;
char ch;
printf("enter a char:");
scanf("%c",&ch);
result=(ch>=65)&&(ch<=90);
printf("result=%d\n",result);
result=(((ch>='A')&&(ch<='Z')) || ((ch>='a') && (ch<='z')));
	printf("result=%d\n",result);
}
