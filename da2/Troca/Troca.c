#include <stdio.h>

void troca(long int*, long int*);

int main()
{
    long int a, b;
    scanf("%ld %ld", &a, &b);
    troca(&a, &b);
    printf("%ld %ld\n", a, b);
    return 0;
}

void troca(long int* ptA, long int* ptB)
{
    long int aux = *ptA;
    *ptA = *ptB;
    *ptB = aux;
}