#include<stdio.h>
main(){
int a=-3,b=0,c=5,d;
d=(b=c)&&(c=a)||(a=b);
printf("a=%d b=%d c=%d d=%d\n",a,b,c,d);
//d=(b=c)||(c=a)||(a=b);
//printf("a=%d b=%d c=%d d=%d\n",a,b,c,d);


}
