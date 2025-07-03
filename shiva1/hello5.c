#include<stdio.h>
void main()
 {
   int n,rev=0,rem,temp;
   printf("enter the value of n\n");
   scanf("%d",&n);
   temp=n;
   while(n>0)
    {
      rem=n%10;
      rev=rev*10+rem;
      n=n/10;
    }
   if(rev==temp)
   printf("palindrome number");
   else
   printf("not palindrome");
  }   
