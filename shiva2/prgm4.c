//program to print your stage based on your age
#include<stdio.h>
int main(){
 int age;
 printf("enter your age:");
 scanf("%d",&age);
 if(age>12 && age<=19){
 printf("teeen age");
 }
 else if(age>19 && age<=30){
 printf("young age");
 }
 else if(age>30 && age<=50){
 printf("middle age");
 }else{
 printf("old age");
 }
 return 0;
 }
