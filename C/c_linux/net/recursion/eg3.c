#include<stdio.h>
int f(int n)
{
if(n==4)
return n;
else return 2*f(n+1);
}
main()
{
printf("%d\n",f(2));
return 0;

}
