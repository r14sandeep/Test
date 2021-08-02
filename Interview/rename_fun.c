#include<stdio.h>
 typedef void govinda(int);
void one(int x){
    printf("FROM ONE %d",x);
}
void two(int y){
    printf("\nFROM TWO %d",y);
}
int main(){
    govinda one,two;
    one(1);
    two(2);
    return 0;        
}
