//cheak whether a number is positive are negative
#include<stdio.h>
int main(){
  int number;
  printf("enter the number? ");
  scanf("%d",&number);
  if(number>=0){
    printf(" number is positive\n");
    }else{
     printf("number is negative\n");
     }
     printf("your number is:  %d",number);
     return 0;
  }   
