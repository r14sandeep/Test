//program using recursion function by keeping exitcondition
#include<stdio.h>
   void printme(){
   static int number=1;
   printf("wellcom %d\n",number);
   if(number<10){
   number++;
   printme();
   }
 }
 int main(){
   printme();
   return 0;
 }  
