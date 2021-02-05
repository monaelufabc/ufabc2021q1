#include<stdio.h>

int main()
{
    int a=7, b=10;
    int *ptA, *ptB;
    printf("Endereco de a: %p\n", &a);
    printf("Endereco de b: %p\n", &b);
    ptA = &a;
    ptB = &b;
    printf("Conteudo de ptA: %p\n", ptA);
    printf("Conteudo de ptB: %p\n", ptB);
    printf("Conteudo de ptA: %p apontado por ptA: %d\n", ptA, *ptA);
    printf("Conteudo de ptB: %p apontado por ptB: %d\n", ptB, *ptB);
    return 0;
}