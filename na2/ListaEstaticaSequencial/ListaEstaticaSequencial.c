#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int chave;
};

struct Lista
{
    struct Item *itens;
    int tamanho, quantidade;
};

struct Lista criaLista(int);
struct Item criaItem(int);
int listaCheia(struct Lista);
int listaVazia(struct Lista);
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
            printf("Item %d%sfoi removido da lista\n", chave, removerLista(&lista, criaItem(chave))?" ":" nao ");
        }
        else if(op == 'B')
        {
            scanf("%d", &chave);
            printf("Item %d%slocalizado na lista\n", chave, buscarLista(lista, criaItem(chave))!=-1?" ":" nao ");
        }
        else // M
        {
            mostrarLista(lista);
        }
    }
    return 0;
}

struct Lista criaLista(int n)
{
    struct Lista l;
    l.quantidade = 0;
    l.tamanho = n;
    l.itens = (struct Item*) malloc(n * sizeof(struct Item));
    return l;
}

struct Item criaItem(int chave)
{
    struct Item it;
    it.chave = chave;
    return it;
}

int listaCheia(struct Lista l)
{
    return l.quantidade == l.tamanho;
}

int listaVazia(struct Lista l)
{
    return l.quantidade == 0;
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
        meio = (dir+esq)/2;
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

int removerLista(struct Lista *l, struct Item it)
{
    int i, j;
    if(!listaVazia(*l))
    {
        i = buscarLista(*l, it);
        if(i != -1)
        {
            for(j=i; j<l->quantidade-1; j++)
            {
                l->itens[j] = l->itens[j+1];
            }
            l->quantidade--;
            return 1;
        }
    }
    return 0;
}