#include <stdio.h>
int main(void)
{
    // allocating memory to p
    int* p = malloc(8);
    *p = 100;
     
    // deallocated the space allocated to p
    free(p);
    free(p);
     
    // core dump/segmentation fault
    //  as now this statement is illegal
    *p = 110;
     
    return 0;
}
