#include<stdio.h>
void f(void);
main()
{
extern int a;
f();
printf("a=%d\n",a);
}
int a=2;
void f(void)
{
printf("a=%d\n",a);
}
