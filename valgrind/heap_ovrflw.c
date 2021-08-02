#include <stdio.h>
#include <stdlib.h>
 void heapoverrun(void)
 {
          int* ptr = malloc(10 * sizeof(int));
          ptr[10] = 0;
          free(ptr);
 }
int main(void)
 {
     int index;
      for(index=0;index<5;index++)
          heapoverrun();
          return 0;
 }
