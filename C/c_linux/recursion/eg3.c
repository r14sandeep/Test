//factorial
#include<stdio.h>
main()
{
int v;
printf("enter v");
scanf("%d",&v);
printf("fact=%d\n",fact(v));

}
int fact(int v)
{
if(v>0)
return(v*fact(v-1));
return 1;


}
