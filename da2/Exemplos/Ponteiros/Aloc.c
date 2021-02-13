#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptInt;
    ptInt = (int*) malloc(sizeof(int));
    printf("Endereco: %p\n", ptInt);
    *ptInt = 7;
    printf("Apontado: %d Endereco: %p\n", *ptInt, ptInt);
    ptInt = (int*) malloc(sizeof(int));
    printf("Endereco: %p\n", ptInt);
    *ptInt = 10;
    printf("Apontado: %d Endereco: %p\n", *ptInt, ptInt);
    free(ptInt);
    return 0;
}