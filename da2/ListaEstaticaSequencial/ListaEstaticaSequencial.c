#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int chave;
};

struct Lista
{
    struct Item *itens;
    int quantidade, tamanho;
};

struct Item criaItem(int);
struct Lista criaLista(int);
int listaCheia(struct Lista);
void inserirLista(struct Lista *, struct Item);
int removerLista(struct Lista *, struct Item);
void mostrarLista(struct Lista);
int buscarLista(struct Lista, struct Item);

int main()
{
    struct Lista lista;
    int n, chave;
    char op;
    scanf("%d", &n);
    lista = criaLista(n);
    while(scanf("\n%c", &op) != EOF)
    {
        if(op == 'I')
        {
            scanf("%d", &chave);
            inserirLista(&lista, criaItem(chave));
        }
        else if(op == 'R')
        {
            scanf("%d", &chave);
            removerLista(&lista, criaItem(chave));
        }
        else if(op == 'B')
        {
            scanf("%d", &chave);
            printf("Item %d%sfoi localizado na lista\n", chave, buscarLista(lista, criaItem(chave))!=-1?" ":" nao ");
        }
        else // M
        {
            mostrarLista(lista);
        }
    }
    return 0;
}

struct Item criaItem(int chave)
{
    struct Item it;
    it.chave = chave;
    return it;
}

struct Lista criaLista(int n)
{
    struct Lista l;
    l.itens = (struct Item*) malloc(n * sizeof(struct Item));
    if(l.itens != NULL)
    {
        l.quantidade = 0;
        l.tamanho = n;
    }
    return l;
}

int listaCheia(struct Lista l)
{
    return l.quantidade == l.tamanho;
}

void inserirLista(struct Lista *l, struct Item novo)
{
    int i, achei, j;
    if(!listaCheia(*l))
    {
        achei = 0;
        i = 0;
        while(i<l->quantidade && !achei)
        {
            if(l->itens[i].chave > novo.chave)
            {
                achei = 1;
            }
            else
            {
                i++;
            }
        }
        for(j=l->quantidade-1; j>=i; j--)
        {
            l->itens[j+1] = l->itens[j];
        }
        l->itens[i] = novo;
        l->quantidade++;
    }
}

void mostrarLista(struct Lista l)
{
    int i;
    for(i=0; i<l.quantidade; i++)
    {
        printf("%d%s", l.itens[i].chave, i<l.quantidade-1?" ":"\n");
    }
}

int buscarLista(struct Lista l, struct Item it)
{
    int esq = 0, dir = l.quantidade-1, meio;
    while(esq <= dir)
    {
        meio = (esq+dir)/2;
        if(l.itens[meio].chave == it.chave)
        {
            return meio;
        }
        else if(l.itens[meio].chave > it.chave)
        {
            dir = meio-1;
        }
        else
        {
            esq = meio+1;
        }
    }
    return -1;
}

int removerLista(struct Lista *l, struct Item rem)
{
    int j, i = buscarLista(*l, rem);
    if(i != -1)
    {
        for(j=i; j<l->quantidade-1; j++)
        {
            l->itens[j] = l->itens[j+1];
        }
        l->quantidade--;
    }
}


















