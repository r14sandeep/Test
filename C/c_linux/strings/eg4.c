#include<stdio.h>
main()
{
char a[16]="abcdefghij123456";
char b[16]="0123456789123456";
printf("a:%s\n b=%s\n",a,b);
printf("%u %u\n",a,b);
a[15]='.';
b[15]='*';
printf("%u %u\n",a,b);
printf("a:%s\n b=%s\n",a,b);




}
