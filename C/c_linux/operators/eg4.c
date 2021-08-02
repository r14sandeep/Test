#include<stdio.h>
main()
{
int a=123,b=3000000,c=4;
int d;
printf("before swapping a=%d,b=%d\n",a,b);
 b=a*b/(a=b);
printf("after swapping a=%d,b=%d\n",a,b);
}
