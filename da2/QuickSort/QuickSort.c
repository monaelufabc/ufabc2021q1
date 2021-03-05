#include <stdio.h>
#include <stdlib.h>

void qSort(int *, int);
void quickSort(int *, int, int);
int particiona(int *, int, int);

int main()
{
    int *v, n, i;
    while(scanf("%d", &n) != EOF)
    {
        v = (int*) malloc(n * sizeof(int));
        for(i=0; i<n; i++)
        {
            scanf("%d", &v[i]);
        }

        qSort(v, n);

        for(i=0; i<n; i++)
        {
            printf("%d%s", v[i], (i<n-1?" ":"\n"));
        }
        free(v);
    }
    return 0;
}

void qSort(int *v, int n)
{
    quickSort(v, 0, n-1);
}

void quickSort(int *v, int e, int d)
{
    int p;
    if(e < d)
    {
        p = particiona(v, e, d);
        quickSort(v, e, p-1);
        quickSort(v, p+1, d);
    }
}

int particiona(int *v, int e, int d)
{
    int aux, i, pm;
    for(i=e, pm=e-1; i<d; i++)
    {
        if(v[i] < v[d])
        {
            pm++;
            aux = v[i];
            v[i] = v[pm];
            v[pm] = aux;
        }
    }
    aux = v[d];
    v[d] = v[pm+1];
    v[pm+1] = aux;
    return pm+1;
}