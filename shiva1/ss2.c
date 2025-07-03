#include <stdio.h>
int main() {
    int base=2, exp;
    long double result = 1.0;
    //printf("Enter a base number: ");
    //scanf("%d", &base);
    printf("Enter an exponent: ");
    scanf("%d", &exp);

    while (exp != 0) {
        result *= base;
        --exp;
    }
    result%2==0?printf("%d is power of 2",exp):printf("%d is not a power of 2",exp);
    return 0;
}
