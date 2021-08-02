#include<stdio.h>
main()
{
int i=1,j=5;
i=3,j=-5;
while(i--&&j++)
{printf("in while: i=%d,j=%d\n",i,j);}
printf("out of while:i=%d,j=%d\n",i,j);



}
