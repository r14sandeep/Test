#include<stdio.h>
int g=10;
void f1(int);
main()
{
auto int l=20;
f1(l);
printf("l=%d,g=%d\n",l,g);
}
void f1(int f)
{
printf("g=%d f=%d\n",g,f);
f++;
g++;
return;
}
