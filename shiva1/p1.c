#include<stdio.h>
void f2(void);
void f1(viod){
printf("before mainn\n");
f2();
printf("bye f1\n");
}
int main(){
printf("in main\n");
f1();
printf("bye main\n");
}
void f2(void){ 
printf("after main\n");
}




                  
