#include<stdio.h>
#include<stdlib.h>
union sag
{
int a;
unsigned char b;
}u={1234};
main()
{
printf("%d",u.b);
if(u.b==34)
{
printf("small");
}
else
printf("bigb");
}
