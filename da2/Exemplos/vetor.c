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

int main()
{
    int a=1, b=2, c=3, d=4, e=5, f=6, g=7, h=8, i=9, j=10;

    printf("%d\n", somaVet(&a));

    return 0;
}