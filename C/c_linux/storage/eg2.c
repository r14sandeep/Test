#include<stdio.h>
void f(void);
extern int v;
main()
{
//int v;
printf("in main v=%d\n",v);
f();
printf("in main v=%d\n",v);
}
void f(void)
{
v+=10;
}
//int v=20;
