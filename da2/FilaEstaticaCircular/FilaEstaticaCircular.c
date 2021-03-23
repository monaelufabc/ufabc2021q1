#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int chave;
};

struct FilaEstaticaCircular
{
    struct Item *itens;
    int tamanho;
    int inicio, fim;
};

struct FilaEstaticaCircular criaFilaEstaticaCircular(int);
struct Item criaItem(int);
void enfileirarCirculando(struct FilaEstaticaCircular *, struct Item);
struct Item desenfileirarCirculando(struct FilaEstaticaCircular *);
int filaCircularVazia(struct FilaEstaticaCircular);
int filaCircularCheia(struct FilaEstaticaCircular);
void mostrarFilaCircular(struct FilaEstaticaCircular);

int main()
{
    struct FilaEstaticaCircular fila;
    int n, chave;
    char op;

    scanf("%d", &n);
    fila = criaFilaEstaticaCircular(n);

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

struct FilaEstaticaCircular criaFilaEstaticaCircular(int n)
{
    struct FilaEstaticaCircular f;
    f.itens = (struct Item*) malloc(n * sizeof(struct Item));
    f.tamanho = n;
    f.inicio = 0;
    f.fim = 0;
    return f;
}

struct Item criaItem(int chave)
{
    struct Item it;
    it.chave = chave;
    return it;
}

void enfileirarCirculando(struct FilaEstaticaCircular *f, struct Item novo)
{
    if(!filaCircularCheia(*f))
    {
        f->itens[f->fim] = novo;
        f->fim = (f->fim+1)%f->tamanho;
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

int filaCircularVazia(struct FilaEstaticaCircular f)
{
    return f.inicio == f.fim;
}

int filaCircularCheia(struct FilaEstaticaCircular f)
{
    return (f.fim+1)%f.tamanho == f.inicio;
}

void mostrarFilaCircular(struct FilaEstaticaCircular f)
{
    int i;
    if(!filaCircularVazia(f))
    {
        for(i=f.inicio; i!=f.fim; i=(i+1)%f.tamanho)
        {
            printf("%d%s", f.itens[i].chave, (i+1)%f.tamanho!=f.fim?" ":"\n");
        }
    }
}

/*
Ultima funcao implementada foi o mostrar().
Ao testar para uma fila de tamanho 5 inserindo 7 elementos, ao mostrar
o primeiro elemento se repetiu indefinidamente...
Possiveis erros:
-> O mostrar estah errado.
-> O enfileirar estah errado.
verificar no inicio da proxima aula.

*/