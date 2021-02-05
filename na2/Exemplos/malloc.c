#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptInt;
    ptInt = (int*) malloc(sizeof(int));
    *ptInt = 666;
    printf("Conteudo de ptInt: %p\n", ptInt);
    printf("Apontado por ptInt: %d\n", *ptInt);
    printf("Endereco de ptInt: %p\n", &ptInt);
    ptInt = (int*) malloc(sizeof(int));
    *ptInt = 7;
    printf("Conteudo de ptInt: %p\n", ptInt);
    free(ptInt);

    return 0;
}
