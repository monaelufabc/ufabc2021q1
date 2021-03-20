#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int chave;
};

struct FilaEstaticaCircular
{
    struct Item *itens;
    int inicio, final;
    int tamanho;
};

struct FilaEstaticaCircular criaFilaCircular(int);
struct Item criaItem(int);
int filaCircularCheia(struct FilaEstaticaCircular);
int filaCircularVazia(struct FilaEstaticaCircular);
void mostrarFilaCircular(struct FilaEstaticaCircular);
void enfileirarCirculando(struct FilaEstaticaCircular *, struct Item);
struct Item desenfileirarCirculando(struct FilaEstaticaCircular *);

int main()
{
    struct FilaEstaticaCircular fila;
    int n, chave;
    char op;

    scanf("%d", &n);

    fila = criaFilaCircular(n);

    while(scanf("\n%c", &op) != EOF)
    {
        if(op == 'E')
        {
            scanf("%d", &chave);
            enfileirarCirculando(&fila, criaItem(chave));
        }
        else if(op == 'D')
        {
            if(!filaCircularVazia(fila))
            {
                printf("Item %d desenfileirado\n", desenfileirarCirculando(&fila).chave);
            }
        }
        else // M
        {
            mostrarFilaCircular(fila);
        }
    }
    return 0;
}

struct FilaEstaticaCircular criaFilaCircular(int n)
{
    struct FilaEstaticaCircular f;
    f.itens = (struct Item*) malloc(n*sizeof(struct Item));
    f.tamanho = n;
    f.inicio = 0;
    f.final = 0;
    return f;
}

struct Item criaItem(int chave)
{
    struct Item it;
    it.chave = chave;
    return it;
}

int filaCircularCheia(struct FilaEstaticaCircular f)
{
    return (f.final+1)%f.tamanho == f.inicio;
}

int filaCircularVazia(struct FilaEstaticaCircular f)
{
    return f.inicio == f.final;
}

void mostrarFilaCircular(struct FilaEstaticaCircular f)
{
    int i;
    for(i=f.inicio; i!=f.final; i=(i+1)%f.tamanho)
    {
        printf("%d%s", f.itens[i].chave, "\n");
    }
}

void enfileirarCirculando(struct FilaEstaticaCircular *f, struct Item novo)
{
    if(!filaCircularCheia(*f))
    {
        f->itens[f->final] = novo;
        f->final = (f->final+1)%f->tamanho;
    }
}

struct Item desenfileirarCirculando(struct FilaEstaticaCircular *f)
{
    struct Item it;
    if(!filaCircularVazia(*f))
    {
        it = f->itens[f->inicio];
        f->inicio = (f->inicio+1)%f->tamanho;
    }
    return it;
}