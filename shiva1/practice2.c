#include<stdio.h>
void main()
{
  int a,b,add,substract,multiply,rem;
  float divide;
  printf("enter values of a and b\n");
  scanf("%d%d",&a,&b);
  add=a+b;
  substract=a-b;
  multiply=a*b;
  divide=(float)a/b;
  rem=a%b;
  printf("sum=%d\n",add);
  printf("difference=%d\n",substract);
  printf("muntiplication=%d\n",multiply);
  printf("division=%d\n",divide);
  printf("remainder=%d\n",rem);
}    
