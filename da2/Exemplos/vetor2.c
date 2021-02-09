#include <stdio.h>

int somaVet(int *v)
{
    int i, s=0;
    for(i = 0; i<10; i++)
    {
        s += v[i];
    }
    return s;
}

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    int a, b, i, soma;
    int vet[10];

    printf("Informando os 10 elementos do vetor:\n");
    for(i=0; i<10; i++)
    {
        scanf("%d", &vet[i]);
    }

    printf("Informando valores para variaveis A e B:\n");
    scanf("%d %d", &a, &b);

    troca(&a, &b);
    printf("Depois de executar troca()\n");
    printf("A: %d B:%d\n", a, b);

    soma = somaVet(vet);
    printf("A Soma dos elementos foi: %d\n", soma);

    return 0;
}