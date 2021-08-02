#include<stdio.h>
void f(int n)
{
if(n==0)
return;
printf("%d\n",n%2);
f(n/2);
}
main()
{
f(25);
//printf("in main %d\n",f(25));

}
