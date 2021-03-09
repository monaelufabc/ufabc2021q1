#include <stdio.h>
#include <stdlib.h>

struct Heap
{
    int *itens;
    int quantidade, tamanho;
};

struct Heap criaHeap(int);
void inserirHeap(struct Heap *, int);
int removerHeap(struct Heap *);
void mostrarHeap(struct Heap);
int filhoDireita(int);
int filhoEsquerda(int);
int ultimoPai(int);
void peneirar(struct Heap *, int);
void constroiHeap(struct Heap *);

int main()
{
    struct Heap h;
    int n, chave;
    char op;

    scanf("%d", &n);
    h = criaHeap(n);

    while(scanf("\n%c", &op) != EOF)
    {
        if(op == 'I')
        {
            scanf("%d", &chave);
            inserirHeap(&h, chave);
        }
        else if(op == 'R')
        {
            if(h.quantidade > 0)
            {
                chave = removerHeap(&h);
                printf("%d\n", chave);
            }
        }
        else // op == 'M'
        {
            mostrarHeap(h);
        }
    }
    return 0;
}

struct Heap criaHeap(int n)
{
    struct Heap h;
    h.itens = (int*) malloc(n * sizeof(int));
    h.tamanho = n;
    h.quantidade = 0;
    return h;
}

void inserirHeap(struct Heap *h, int chave)
{
    if(h->quantidade < h->tamanho)
    {
        h->itens[h->quantidade] = chave;
        h->quantidade++;
        constroiHeap(h);
    }
}

int removerHeap(struct Heap *h)
{
    int aux;
    if(h->quantidade > 0)
    {
        aux = h->itens[0];
        h->itens[0] = h->itens[h->quantidade-1];
        h->itens[h->quantidade-1] = aux;
        h->quantidade --;
        peneirar(h, 0);
    }
    return aux;
}

void mostrarHeap(struct Heap h)
{
    int i;
    for(i=0; i<h.quantidade; i++)
    {
        printf("%d%s", h.itens[i], i<h.quantidade-1?" ":"\n");
    }
}

int filhoDireita(int p)
{
    return 2*p+2;
}

int filhoEsquerda(int p)
{
    return 2*p+1;
}

int ultimoPai(int n)
{
    return n/2-1;
}

void peneirar(struct Heap *h, int p)
{
    int aux, iMaior = p;
    if(filhoDireita(p) < h->quantidade && h->itens[filhoDireita(p)] > h->itens[iMaior])
    {
        iMaior = filhoDireita(p);
    }
    if(filhoEsquerda(p) < h->quantidade && h->itens[filhoEsquerda(p)] > h->itens[iMaior])
    {
        iMaior = filhoEsquerda(p);
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
    for(i=ultimoPai(h->quantidade); i>=0; i--)
    {
        peneirar(h, i);
    }
}