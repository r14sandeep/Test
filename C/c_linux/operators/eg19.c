#include<stdio.h>
void f(int,int,int);
main()
{
int a=-5,b=4,c=5,d;
printf("a=%d,b=%d,c=%d\n",a=b,b<0,a=0);
f(a=b,b<0,a=0);//function call
printf("a=%d,b=%d,c=%d\n",a,b,c);
//printf("%d %d %d\n",a>b,a=c,a<b);
//printf("%d\n",a);
}
void f(int x,int y,int z)
{
printf("x=%d y=%d z=%d\n",x,y,z);
}
