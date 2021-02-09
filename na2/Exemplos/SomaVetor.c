#include<stdio.h>
#include <stdlib.h>

int somaVetor(int *, int);

/*
int main()
{
    int v[] = {1,2,3,4,5,6,7,8,9,10}, s;
    s = somaVetor(v, 10);
    printf("%d\n", s);
    return 0;
}
*/

/*
int main()
{
    int a=10, b=20, c=30, d=40, e=50, f=60, g=70, h=80, i=90, j=100, s;
    s = somaVetor(&a, 10);
    printf("%d\n", s);
    return 0;
}
*/

int main()
{
    int *v, n, s, i;

    scanf("%d", &n);
    v = (int*) malloc(n * sizeof(int));

    printf("v: %p\n", v);
    printf("&v[0]: %p\n", &v[0]);
    printf("&v: %p\n", &v);

    for(i=0; i<n; i++)
    {
        scanf("%d", &v[i]);
    }

    s = somaVetor(v, n);

    printf("%d\n", s);
    return 0;
}

int somaVetor(int *vetor, int n)
{
    int s=0, i;
    for(i=0; i<n; i++)
    {
        s += vetor[i];
    }
    return s;
}