#include<stdio.h>
#include<ctype.h>
int main(){
   char ch;
   puts("enter the charecter:");
   scanf("%c",&ch);
   isupper(ch)?ch+=32:islower(ch)?ch-=32:printf("entered non alhabet cahrecter\n");
  printf("%c\n",ch);
  return 0;
}


