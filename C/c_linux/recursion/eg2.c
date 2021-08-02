//sum of digits
#include<stdio.h>
int sum(int v)
{
if(v==0) return 0;
return((v%10)+sum(v/10));
}
main()
{
int v;
printf("enter v");
scanf("%d",&v);
printf("sum=%d\n",sum(v));


}
