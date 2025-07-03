//arrays
#define students 6
#include<stdio.h>
int main(){
  float per[students];
  for(int i=0;i<students;i++){
     printf("enter roll number %d percentage ",i+1);
     scanf("%f",&per[i]);
     float lowest=per[0];
     float highest=per[0];
     for(int i=1;i<students;i++){
      if(per[i]<lowest){
       lowest=per[i];
       if(per[i]<highest){
        highest=per[i];
        }
        }
       printf("highest number if %f",highest);
       printf("lowest number if %f",lowest);
       }
     if(per[i]<0||per[i]>100){
       printf("say your percentage again");
       i=i-1;
       }
     }
     for(int i=0;i<students;i++){
          if(per[i]<70){
          printf("rool number %d attend the sunday special class\n",i+1);
          }
         } 
     return 0;
    }  
  
