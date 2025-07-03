#include<stdio.h>
int main(){
      int a=123,b=456;
      a^=b^=a^=b;
      printf("%d%d\n",a,b);
      return 0;
}
