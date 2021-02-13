#include <stdio.h>

int main()
{
    long int a = 7, b = 10;
    long int *ptA, *ptB;
    printf("Endereco de a: %p\n", &a);
    printf("Endereco de b: %p\n", &b);
    ptA = &a;
    ptB = &b;
    printf("Conteudo de ptA: %p\n", ptA);
    printf("Conteudo de ptB: %p\n", ptB);
    printf("Apontado por ptA: %ld\n", *ptA);
    printf("Apontado por ptB: %ld\n", *ptB);
    return 0;
}