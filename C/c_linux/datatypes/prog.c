#include<stdio.h>
main()
{
unsigned short int s;
unsigned int i;
unsigned long int l;
i=l=s=0;
printf("%hu %u %lu\n",s,i,l);
s=s-2;
i=i-2;
l=l-2;
printf("%hu,%u,%lu\n",s,i,l);


}
