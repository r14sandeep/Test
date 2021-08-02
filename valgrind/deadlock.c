#include<stdio.h>
#include <stdlib.h>
   
int main(void)
{
     int *ptr = malloc(10 * sizeof(int));
     int num=10;
     printf("%p\n",ptr);
     *ptr = num;
     printf("%d\n",*ptr);
     free(ptr);
     *ptr = num;
     printf("%d\n",*ptr);
     return 0;
 }
