#include<stdio.h>
int f(int x,int y)
{
if(x==0)
return y;
return f(x-1,x+y);
}
main()
{
//f(4,3);
printf("%d\n",f(4,3));

}
