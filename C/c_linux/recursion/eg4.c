//fibnocci series
#include<stdio.h>
main()
{
int v,i;
printf("enter v");
scanf("%d",&v);
//for(i=1;i<=v;i++)
printf("%d,",fib(v));


}
int fib(int v)
{
if(v==1) return 0;
if(v==2) return 1;
return(fib(v-2)+fib(v-1));

}
