#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *, int);

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

        selectionSort(v, n);

        for(i=0; i<n; i++)
        {
            printf("%d%s", v[i], (i<n-1?" ":"\n"));
        }
        free(v);
    }
    return 0;
}

void selectionSort(int *v, int n)
{
    int i, j, iMin, aux;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1, iMin = i; j<n; j++)
        {
            if(v[j] < v[iMin])
            {
                iMin = j;
            }
        }
        aux = v[iMin];
        v[iMin] = v[i];
        v[i] = aux;
    }
}