/*write a c program to find largest of 2 numbers*/
#include<stdio.h>
void main()
 {
   int num1,num2;
   printf("enter two integrs\n");
   scanf("%d%d",&num1,&num2);
   if(num1>num2)
  {
    printf("largest number is %d",num1);
  }
  else
  {
   printf("largest number is %d",num2);
  }
}
