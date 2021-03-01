#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *, int);

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

        selectionSort(v, n);

        for(i=0; i<n; i++)
        {
            printf("%d%s", v[i], i<n-1?" ":"\n");
        }
        free(v);
    }
    return 0;
}

void selectionSort(int *v, int n)
{
    int i, j, aux, iMin;
    for(i=0; i<n-1; i++)
    {
        iMin=i;
        for(j=i+1; j<n; j++)
        {
            if(v[j] < v[iMin])
            {
                iMin = j;
            }
        }
        aux = v[i];
        v[i] = v[iMin];
        v[iMin] = aux;
    }
}