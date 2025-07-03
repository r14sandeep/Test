/*wriye a c program to perform all arithmetic operation on 2 integer number*/
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
   printf("multiply=%d\n",multiplication);
   printf("division=%f\n",divide);
   printf("remainder=%d\n",rem);
  } 
