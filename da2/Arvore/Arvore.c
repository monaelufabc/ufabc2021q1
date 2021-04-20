#include <stdio.h>
#include <stdlib.h>

struct No
{
    int chave;
    struct No *pai;
    struct No *direita;
    struct No *esquerda;
};

struct Arvore
{
    struct No *raiz;
};

struct Arvore * criaArvore();
struct No * criaNo(int);
void inserir(struct Arvore *, struct No *);
void preOrder(struct No *);
void inOrder(struct No *);
void postOrder(struct No *);
struct No * remover(struct Arvore *, int);
struct No * sucessor(struct No *);

int main()
{
    struct Arvore *arvore = criaArvore();
    struct No *no;
    int chave, ret;
    char op;

    while(scanf("\n%c", &op) != EOF)
    {
        if(op == 'I')
        {
            ret = scanf("%d", &chave);
            inserir(arvore, criaNo(chave));
        }
        else if(op == 'R')
        {
            ret = scanf("%d", &chave);
            no = remover(arvore, chave);
            if(no != NULL)
            {
                printf("item %d removido da arvore\n", no->chave);
                free(no);
            }
        }
        else // M
        {
            ret = scanf("\n%c", &op);
            if(op == 'P')
            {
                preOrder(arvore->raiz);
            }
            else if(op == 'I')
            {
                inOrder(arvore->raiz);
            }
            else // T
            {
                postOrder(arvore->raiz);
            }
        }
    }
    return 0;
}

struct Arvore * criaArvore()
{
    struct Arvore *t = (struct Arvore*) malloc(sizeof(struct Arvore));

    if(t != NULL)
    {
        t->raiz = NULL;
    }
    return t;
}

struct No * criaNo(int chave)
{
    struct No * no = (struct No*) malloc(sizeof(struct No));

    if(no != NULL)
    {
        no->chave = chave;
        no->esquerda = NULL;
        no->direita = NULL;
        no->pai = NULL;
    }
    return no;
}

void inserir(struct Arvore *t, struct No *novo)
{
    struct No *pai = NULL, *filho = t->raiz;

    while(filho != NULL)
    {
        pai = filho;
        if(filho->chave < novo->chave)
        {
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }

    if(pai != NULL) // inserindo no folha
    {
        novo->pai = pai;
        if(pai->chave > novo->chave) // filho da esquerda
        {
            pai->esquerda = novo;
        }
        else // filho da direita
        {
            pai->direita = novo;
        }
    }
    else // inserindo no raiz
    {
        t->raiz = novo;
    }
}

void preOrder(struct No *r)
{
    if(r != NULL)
    {
        printf("%d\n", r->chave);
        preOrder(r->esquerda);
        preOrder(r->direita);
    }
}

void postOrder(struct No *r)
{
    if(r != NULL)
    {
        postOrder(r->esquerda);
        postOrder(r->direita);
        printf("%d\n", r->chave);
    }
}

void inOrder(struct No *r)
{
    if(r != NULL)
    {
        inOrder(r->esquerda);
        printf("%d\n", r->chave);
        inOrder(r->direita);
    }
}

struct No * remover(struct Arvore *t, int chave)
{
    struct No *anterior = NULL, *filho = t->raiz, *subs;

    while(filho != NULL && filho->chave != chave)
    {
        anterior = filho;
        if(filho->chave < chave)
        {
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }

    if(filho != NULL)
    {
        if(filho->esquerda == NULL && filho->direita == NULL) // eh folha
        {
            if(anterior != NULL) // e nao eh raiz
            {
                if(anterior->esquerda == filho)
                {
                    anterior->esquerda = NULL;
                }
                else
                {
                    anterior->direita = NULL;
                }
            }
            else // e eh raiz
            {
                t->raiz = NULL;
            }
        }
        else if(filho->esquerda != NULL && filho->direita != NULL) // pai de dois filhos
        {
            subs = sucessor(filho->direita);

            if(anterior != NULL) // nao eh raiz
            {
                if(anterior->esquerda == filho) // eh filho esquerdo do seu pai
                {
                    anterior->esquerda = subs;
                }
                else // eh filho direito do seu pai
                {
                    anterior->direita = subs;
                }
            }
            else // eh raiz
            {
                t->raiz = subs;
            }
            subs->pai = anterior; // sucessor/antecessor assume pai de filho como seu pai
            subs->esquerda = filho->esquerda; // sucessor/antecessor assume subarvore da esquerda de filho, se houver
            if(filho->esquerda != NULL) // se houver subarvore esquerda de filho, entao
            {
                filho->esquerda->pai = subs; //raiz da subarvore esquerda de filho assume antecessor/sucessor como pai
            }
            subs->direita = filho->direita;
            if(filho->direita != NULL)
            {
                filho->direita->pai = subs;
            }
        }
        else // pai de filho unico
        {
            if(anterior != NULL) // eh no interno
            {
                if(anterior->esquerda == filho) // eh filho da esquerda do pai
                {
                    if(filho->esquerda != NULL) // e tem filho esquerdo
                    {
                        anterior->esquerda = filho->esquerda;
                    }
                    else // e tem filho direito
                    {
                        anterior->esquerda = filho->direita;
                    }
                }
                else // eh filho da direita do pai
                {
                    if(filho->esquerda != NULL)
                    {
                        anterior->direita = filho->esquerda;
                    }
                    else
                    {
                        anterior->direita = filho->direita;
                    }
                }
            }
            else // eh raiz
            {
                if(filho->esquerda != NULL)
                {
                    t->raiz = filho->esquerda;
                }
                else
                {
                    t->raiz = filho->direita;
                }
                t->raiz->pai = NULL;
            }
        }
    }
    return filho;
}

struct No * sucessor(struct No *filho)
{
    struct No *anterior = NULL;

    while(filho != NULL)
    {
        anterior = filho;
        filho = filho->esquerda;
    }

    if(anterior->pai->esquerda == anterior) // sucessor eh filho esquerdo do seu pai
    {
        anterior->pai->esquerda = anterior->direita; // avo assume o neto da direita do sucessor, se houver
        if(anterior->direita != NULL)
        {
            anterior->direita->pai = anterior->pai;
        }
    }
    else // sucessor eh filho direito do seu pai
    {
        anterior->pai->direita = anterior->direita;
        if(anterior->direita != NULL)
        {
            anterior->direita->pai = anterior->pai;
        }
    }
    return anterior;
}