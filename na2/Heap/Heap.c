#include <stdio.h>
#include <stdlib.h>

struct Heap
{
    int *itens;
    int tamanho;
};

struct Heap criaHeap(int);
int filhoEsquerda(int);
int filhoDireita(int);
int ultimoPai(int);
void peneirar(struct Heap *, int);
void constroiHeap(struct Heap *);

int main()
{
    struct Heap h;
    int n, i;
    while(scanf("%d", &n) != EOF)
    {
        h = criaHeap(n);

        for(i=0; i<h.tamanho; i++)
        {
            scanf("%d", &h.itens[i]);
        }

        constroiHeap(&h);

        for(i=0; i<h.tamanho; i++)
        {
            printf("%d%s", h.itens[i], i<h.tamanho-1?" ":"\n");
        }

        free(h.itens);
    }
    return 0;
}

struct Heap criaHeap(int n)
{
    struct Heap h;
    h.tamanho = n;
    h.itens = (int*) malloc(n * sizeof(int));
    return h;
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
    return n/2-1;
}

void peneirar(struct Heap *h, int p)
{
    int iMaior = p, aux;

    if(filhoEsquerda(p) < h->tamanho && h->itens[filhoEsquerda(p)] > h->itens[iMaior])
    {
        iMaior = filhoEsquerda(p);
    }
    if(filhoDireita(p) < h->tamanho && h->itens[filhoDireita(p)] > h->itens[iMaior])
    {
        iMaior = filhoDireita(p);
    }
    if(iMaior != p)
    {
        aux = h->itens[p];
        h->itens[p] = h->itens[iMaior];
        h->itens[iMaior] = aux;
        peneirar(h, iMaior);
    }
}

void constroiHeap(struct Heap *h)
{
    int i;
    for(i=ultimoPai(h->tamanho); i>=0; i--)
    {
        peneirar(h, i);
    }
}