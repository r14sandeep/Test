#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
    char *ptr = (char*)malloc(1);
    *ptr = 'a'; 

    char ch = *ptr;
    printf("\n [%c]\n",ch);
    free(ptr);
    free(ptr);
    return 0;
}
