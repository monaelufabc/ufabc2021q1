#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int chave;
    struct Item *proximo;
};

struct Fila
{
    struct Item *inicio;
    struct Item *final;
};

struct Fila * criaFila();
struct Item * criaItem(int);
int filaVazia(struct Fila *);
void enfileirar(struct Fila *, struct Item *);
struct Item * desenfileirar(struct Fila *);
void mostrarFila(struct Fila *);

int main()
{
    struct Fila *fila = criaFila();
    struct Item *it;
    int chave;
    char op;

    while(scanf("\n%c", &op) != EOF)
    {
        if(op == 'E')
        {
            scanf("%d", &chave);
            enfileirar(fila, criaItem(chave));
        }
        else if(op == 'D')
        {
            it = desenfileirar(fila);
            if(it != NULL)
            {
                printf("Item %d desenfileirado\n", it->chave);
                free(it);
            }
        }
        else //M
        {
            mostrarFila(fila);
        }
    }
    free(fila);
    return 0;
}

struct Fila * criaFila()
{
    struct Fila *f = (struct Fila*) malloc(sizeof(struct Fila));
    if(f != NULL)
    {
        f->inicio = NULL;
        f->final = NULL;
    }
    return f;
}

struct Item * criaItem(int chave)
{
    struct Item *it = (struct Item *) malloc(sizeof(struct Item));
    if(it != NULL)
    {
        it->chave = chave;
        it->proximo = NULL;
    }
    return it;
}

int filaVazia(struct Fila *f)
{
    return f->inicio == NULL && f->final == NULL;
}

void enfileirar(struct Fila *f, struct Item *novo)
{
    if(filaVazia(f))
    {
        f->inicio = novo;
    }
    else
    {
        f->final->proximo = novo;
    }
    f->final = novo;
}

struct Item * desenfileirar(struct Fila *f)
{
    struct Item *it = f->inicio;

    if(!filaVazia(f))
    {
        if(f->inicio == f->final)
        {
            f->final = NULL;
        }
        f->inicio = f->inicio->proximo;
    }
    return it;
}

void mostrarFila(struct Fila *f)
{
    struct Item *it = f->inicio;

    while(it != NULL)
    {
        printf("%d%s", it->chave, it->proximo!=NULL?" ":"\n");
        it = it->proximo;
    }
}