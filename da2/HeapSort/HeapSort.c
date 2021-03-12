#include <stdio.h>
#include <stdlib.h>

int filhoEsquerda(int);
int filhoDireita(int);
int ultimoPai(int);
void peneirar(int *, int, int);
void constroiHeap(int *, int);
int removeMax(int *, int);
void heapSort(int *, int);

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

        heapSort(v, n);

        for(i=0; i<n; i++)
        {
            printf("%d%s", v[i], i<n-1?" ":"\n");
        }
        free(v);
    }

}

int filhoEsquerda(int p)
{
    return 2*p+1;
}

int filhoDireita(int p)
{
    return 2*p+2;
}

int ultimoPai(int n)
{
    return (n/2)-1;
}

void peneirar(int *h, int n, int p)
{
    int aux, iMaior = p;
    if(filhoDireita(p) < n && h[filhoDireita(p)] > h[iMaior])
    {
        iMaior = filhoDireita(p);
    }
    if(filhoEsquerda(p) < n && h[filhoEsquerda(p)] > h[iMaior])
    {
        iMaior = filhoEsquerda(p);
    }
    if(iMaior != p)
    {
        aux = h[p];
        h[p] = h[iMaior];
        h[iMaior] = aux;
        peneirar(h, n, iMaior);
    }
}

void constroiHeap(int *h, int n)
{
    int i;
    for(i=ultimoPai(n); i>=0; i--)
    {
        peneirar(h, n, i);
    }
}

int removeMax(int *h, int n)
{
    int aux = h[0];
    h[0] = h[n-1];
    h[n-1] = aux;
    return n-1;
}

void heapSort(int *h, int n)
{
    int i;
    constroiHeap(h, n);
    for(i=n; i>0; i--)
    {
        n = removeMax(h, n);
        peneirar(h, n, 0);
    }
}