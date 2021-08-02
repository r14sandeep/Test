#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
    char *ptr = (char*)malloc(2);
    char ch = 's'; 

    ptr = ch; 

    printf("[%c]\n",ch); 
    free(ptr);
    return 0;
}
