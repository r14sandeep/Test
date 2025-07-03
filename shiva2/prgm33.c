#include<stdio.h>
int main(){
  int rows;
  int columbs;
  printf("enter the rows:");
  scanf("%d",&rows);
  printf("enter the columbs:");
  scanf("%d",&columbs);
  for(int i=1;i<=rows;i++){
    for(int j=1;j<=columbs;j++){
       if(i==1 || i==rows || j==1 || j==columbs){
       printf("* ");
          }else{
             printf("  ");
            }
          }
          printf("\n");
         }    
   return 0;
 }            
