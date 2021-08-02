#include<stdio.h>
int fib(int val)
{
           if(val==1) return 0;
           if(val==2) return 1;
           return (fib(val-2)+fib(val-1));
}
int main()
{
        int num,index;
	printf("enter a val:");
	scanf("%d",&num);
         for(index=1;index<=num;index++)
              printf("%d ",fib(index));
}          
