#include<stdio.h>
void main()
 {
  int fib1=0,fib2=1,fib3,num,i;
  scanf("%d",fib1);
  printf("first %d FIBONACCI numbers are \n",num);
  printf("%d\n",fib1);
  printf("%d\n",fib2);
  for(i=2;i<num;i++)
   {
     fib3=fib1+fib2;
     printf("%d\n",fib3);
     fib1=fib2;
     fib2=fib3;
    }
   }  
