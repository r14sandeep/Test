#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
    char *ptr = malloc(1);
    char ch;
    *ptr = 'a'; 

    ch = *ptr; 

    printf("\n [%c]\n",ch); 

    return 0;
}
