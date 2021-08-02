#include<stdio.h>
main()
{
int x=20,y=35;
x=y++ + x++;
y=++x + ++y;
printf("x=%d,y=%d",x,y);


}
