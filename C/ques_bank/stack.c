#include<stdio.h>
void func(int *p) 
{
    int i;
    if (!p)
        func(&i);
    else if (p < &i)
        printf("Stack grows upward\n");
    else
        printf("Stack grows downward\n");
}
int main()
{
func(NULL);
}
