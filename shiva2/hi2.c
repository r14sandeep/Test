#include<stdio.h>
int main()
{
  int rank;
  printf("enter your rank: ");
  scanf("%d",&rank);
  if(rank<100){
  printf("outstanding \n");}
  if(rank<1000){
   printf("topper \n");}
    if(rank<10000){
     printf("above avarage \n");}
      if(rank<300000){
       printf("avarage \n"); }
       else{
  printf("study well \n");
  }
  return 0;
}
 
 
