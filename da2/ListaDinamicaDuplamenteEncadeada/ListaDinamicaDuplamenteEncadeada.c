#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int chave;
    struct Item *anterior, *proximo;
};

struct Lista
{
    struct Item *primeiro, *ultimo;
};

struct Lista * criaLista();
struct Item * criaItem(int);
int listaVazia(struct Lista *);
void inserir(struct Lista *, struct Item *);
struct Item * remover(struct Lista *, int);
struct Item * buscar(struct Lista *, int);
void mostrarListaPrimeiroUltimo(struct Lista *);
void mostrarListaUltimoPrimeiro(struct Lista *);

int main()
{
    struct Lista *lista = criaLista();
    struct Item *it;
    int chave;
    char op;

    while(scanf("\n%c", &op) != EOF)
    {
        if(op == 'I')
        {
            scanf("%d", &chave);
            inserir(lista, criaItem(chave));
        }
        else if(op == 'R')
        {
            scanf("%d", &chave);
            it = remover(lista, chave);
            if(it != NULL)
            {
                printf("item %d removido da lista\n", it->chave);
                free(it);
            }
        }
        else if(op == 'B')
        {
            scanf("%d", &chave);
            printf("item %d%slocalizado na lista\n", chave, buscar(lista, chave)!=NULL?" ":" nao ");
        }
        else if(op == 'P')
        {
            mostrarListaPrimeiroUltimo(lista);
        }
        else // U
        {
            mostrarListaUltimoPrimeiro(lista);
        }
    }
    return 0;
}

struct Lista * criaLista()
{
    struct Lista *l = (struct Lista *) malloc(sizeof(struct Lista));

    if(l != NULL)
    {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

struct Item * criaItem(int chave)
{
    struct Item *it = (struct Item *) malloc(sizeof(struct Item));

    if(it != NULL)
    {
        it->chave = chave;
        it->anterior = NULL;
        it->proximo = NULL;
    }
    return it;
}

int listaVazia(struct Lista *l)
{
    return l->primeiro == NULL && l->ultimo == NULL;
}

void inserir(struct Lista *l, struct Item *novo)
{
    struct Item *atual = l->primeiro;

    while(atual != NULL && atual->chave < novo->chave)
    {
        atual = atual->proximo;
    }

    if(atual != NULL) // meio ou inicio nao vazia
    {
        novo->anterior = atual->anterior;
        novo->proximo = atual;

        if(atual->anterior != NULL) // meio
        {
            atual->anterior->proximo = novo;
        }
        else //inicio
        {
            l->primeiro = novo;
        }
        atual->anterior = novo;
    }
    else if(listaVazia(l)) // inicio lista vazia
    {
        l->primeiro = novo;
        l->ultimo = novo;
    }
    else // ultimo
    {
        l->ultimo->proximo = novo;
        novo->anterior = l->ultimo;
        l->ultimo = novo;
    }
}

/*  VERIFICAR ERRO NA PROXIMA AULA:
    SEGMENTATION FAULT AO REMOVER O UNICO ELEMENTO DA LISTA */

struct Item * remover(struct Lista *l, int chave)
{
    struct Item *atual = buscar(l, chave);

    if(atual != NULL)
    {
        if(atual->anterior != NULL) // removendo meio ou ultimo
        {
            if(atual->proximo != NULL) // meio
            {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            }
            else // ultimo
            {
                atual->anterior->proximo = atual->proximo;
                l->ultimo = atual->anterior;
            }
        }
        else // removendo primeiro
        {
            atual->proximo->anterior = atual->anterior;
            l->primeiro = atual->proximo;
        }
    }
    return atual;
}

struct Item * buscar(struct Lista *l, int chave)
{
    struct Item *it = l->primeiro;

    while(it != NULL && it->chave < chave)
    {
        it = it->proximo;
    }

    if(it != NULL && it->chave != chave)
    {
        it = NULL;
    }
    return it;
}

void mostrarListaPrimeiroUltimo(struct Lista *l)
{
    struct Item *it = l->primeiro;

    while(it != NULL)
    {
        printf("%d%s", it->chave, it->proximo!=NULL?" ":"\n");
        it = it->proximo;
    }
}

void mostrarListaUltimoPrimeiro(struct Lista *l)
{
    struct Item *it = l->ultimo;

    while(it != NULL)
    {
        printf("%d%s", it->chave, it->anterior!=NULL?" ":"\n");
        it = it->anterior;
    }
}