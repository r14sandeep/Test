#include<stdio.h>
main()
{
int a=-3,b=0,c=5,d;
//d=(a!=0)&&2&~c;
//printf("%d\n",d);
d=(a<0)||(b>0)^(c!=0)&c^(a<0);
printf("%d\n",d);

}
