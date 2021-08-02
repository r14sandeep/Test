#include<stdio.h>
//comment
void f1(void);
void f2(void);

void f1(void)
{
printf("in f1\n");
f2();
}
int main()
{
printf("in main\n");
f1();
printf("in main\n");
f2();
printf("in main\n");
}
void f2(void)
{
printf("in f2\n");
}
