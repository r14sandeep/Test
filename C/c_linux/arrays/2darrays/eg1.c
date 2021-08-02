#include<stdio.h>
main()
{
int a[][4]={{11,22},{33,44,55,66},{77,88}};
printf("%u\n",a);
printf("%u\n",*a);
printf("%u\n",*a+1);
printf("%u\n",*(a+1));

}
