#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int chave;
};

struct PilhaEstatica
{
    struct Item *itens;
    int topo;
    int tamanho;
};

struct PilhaEstatica criaPilha(int);
struct Item criaItem(int);
int pilhaVazia(struct PilhaEstatica);
int pilhaCheia(struct PilhaEstatica);
void empilhar(struct PilhaEstatica *, struct Item);
struct Item desempilhar(struct PilhaEstatica *);
void mostrarPilhaBaseTopo(struct PilhaEstatica);
void mostrarPilhaTopoBase(struct PilhaEstatica);


int main()
{
    struct PilhaEstatica pilha;
    int n, chave;
    char op;

    scanf("%d", &n);

    pilha = criaPilha(n);

    while(scanf("\n%c", &op) != EOF)
    {
        if(op == 'E')
        {
            scanf("%d", &chave);
            empilhar(&pilha, criaItem(chave));
        }
        else if(op == 'D')
        {
            if(!pilhaVazia(pilha))
            {
                printf("Item %d desempilhado\n", desempilhar(&pilha).chave);
            }
        }
        else if(op == 'B')
        {
            mostrarPilhaBaseTopo(pilha);
        }
        else // T
        {
            mostrarPilhaTopoBase(pilha);
        }
    }
    return 0;
}

struct PilhaEstatica criaPilha(int n)
{
    struct PilhaEstatica p;
    p.itens = (struct Item *) malloc(n * sizeof(struct Item));
    p.tamanho = n;
    p.topo = -1;
    return p;
}

struct Item criaItem(int chave)
{
    struct Item it;
    it.chave = chave;
    return it;
}

int pilhaVazia(struct PilhaEstatica p)
{
    return p.topo == -1;
}

int pilhaCheia(struct PilhaEstatica p)
{
    return p.topo == p.tamanho-1;
}

void empilhar(struct PilhaEstatica *p, struct Item novo)
{
    if(!pilhaCheia(*p))
    {
        p->topo++;
        p->itens[p->topo] = novo;
    }
}

struct Item desempilhar(struct PilhaEstatica *p)
{
    struct Item it;
    if(!pilhaVazia(*p))
    {
        it = p->itens[p->topo];
        p->topo--;
    }
    return it;
}

void mostrarPilhaBaseTopo(struct PilhaEstatica p)
{
    int i;
    if(!pilhaVazia(p))
    {
        for(i=0; i<=p.topo; i++)
        {
            printf("%d%s", p.itens[i].chave, i!=p.topo?" ":"\n");
        }
    }
}

void mostrarPilhaTopoBase(struct PilhaEstatica p)
{
    int i;
    for(i=p.topo; i>=0; i--)
    {
        printf("%d%s", p.itens[i].chave, i!=0?" ":"\n");
    }
}