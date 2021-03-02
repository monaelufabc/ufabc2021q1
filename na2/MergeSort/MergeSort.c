#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *, int, int);
void intercala(int *, int, int, int);

int main()
{
    int n, *v, i;

    while(scanf("%d", &n) != EOF)
    {
        v = (int*) malloc(n * sizeof(int));

        for(i=0; i<n; i++)
        {
            scanf("%d", &v[i]);
        }

        mergeSort(v, 0, n-1);

        for(i=0; i<n; i++)
        {
            printf("%d%s", v[i], i<n-1?" ":"\n");
        }
        free(v);
    }
    return 0;
}

void mergeSort(int *v, int e, int d)
{
    int meio;
    if(e < d)
    {
        meio = (e+d)/2;
        mergeSort(v, e, meio);
        mergeSort(v, meio+1, d);
        intercala(v, e, meio+1, d);
    }
}

void intercala(int *v, int e, int m, int d)
{
    int esq_fim = m-1, tamanho = d-e+1, *vTemp, i, j, iTemp;
    vTemp = (int*) malloc(tamanho * sizeof(int));

    for(i=e, j=m, iTemp=0; i<=esq_fim && j<=d; iTemp++)
    {
        if(v[i] < v[j])
        {
            vTemp[iTemp] = v[i];
            i++;
        }
        else
        {
            vTemp[iTemp] = v[j];
            j++;
        }
    }

    for(;i<=esq_fim; i++, iTemp++)
    {
        vTemp[iTemp] = v[i];
    }

    for(;j<=d; j++, iTemp++)
    {
        vTemp[iTemp] = v[j];
    }

    for(i=e, j=0; i<=d; i++, j++)
    {
        v[i] = vTemp[j];
    }
    free(vTemp);
}