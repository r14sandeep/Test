#include<stdio.h>
main()
{
int a=-5,b=4,c=5,d;
d=a++ + b++ + c--;

printf("a=%d b=%d c=%d d=%d\n",a,b,c,d);
a=--b + --c + --d;
printf("a=%d b=%d c=%d d=%d \n",a,b,c,d);
b=c++ + --d + a--;
printf("a=%d b=%d c=%d d=%d\n",a,b,c,d);

}
