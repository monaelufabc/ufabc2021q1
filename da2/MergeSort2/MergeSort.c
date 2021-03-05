#include <stdio.h>
#include <stdlib.h>

void mSort(int *, int);
void mergeSort(int *, int, int);
void intercala(int *, int, int, int);

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

        mSort(v, n);

        for(i=0; i<n; i++)
        {
            printf("%d%s", v[i], (i<n-1?" ":"\n"));
        }
        free(v);
    }
    return 0;
}


void mSort(int *v, int n)
{
    mergeSort(v, 0, n-1);
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
    int i, j, limEsq = m-1, tam = (d-e)+1, *vTemp, iTemp;

    vTemp = (int*) malloc(tam*sizeof(int));

    for(i=e, j=m, iTemp=0; i<=limEsq && j<=d; iTemp++)
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

    for(; i<=limEsq; i++, iTemp++)
    {
        vTemp[iTemp] = v[i];
    }

    for(; j<=d; j++, iTemp++)
    {
        vTemp[iTemp] = v[j];
    }

    for(i=e, j=0; i<=d; i++, j++)
    {
        v[i] = vTemp[j];
    }
    free(vTemp);
}