//to printf decending order by useing do-while loop
#include<stdio.h>
int main(){
 int number;
 printf("enter the number: ");
 scanf("%d",&number);
  do{
   printf("%d\n",number);
   number--;
   }while(number>=0);
 return 0;
}  
