#include <stdio.h>
#include <stdlib.h>

struct Jogador
{
    char nome[50];
    int qtdGols;
};

struct Time
{
    char nome[50];
    int qtdJogadores;
    struct Jogador *equipe;
};

int calculaMediaGols(struct Jogador *, int);

int main()
{
    int n, i, j, media;
    struct Time *times;
    scanf("%d", &n);
    times = (struct Time*) malloc(n * sizeof(struct Time));
    for(i=0; i<n; i++)
    {
        scanf("%s", times[i].nome);
        scanf("%d", &times[i].qtdJogadores);
        times[i].equipe = (struct Jogador*) malloc(times[i].qtdJogadores * sizeof(struct Jogador));
        for(j=0; j<times[i].qtdJogadores; j++)
        {
            scanf("%s", times[i].equipe[j].nome);
            scanf("%d", &times[i].equipe[j].qtdGols);
        }
    }

    for(i=0; i<n; i++)
    {
        media = calculaMediaGols(times[i].equipe, times[i].qtdJogadores);
        for(j=0; j<times[i].qtdJogadores; j++)
        {
            if(times[i].equipe[j].qtdGols > media)
            {
                printf("[%s] %s\n", times[i].nome, times[i].equipe[j].nome);
            }
        }
    }
}

int calculaMediaGols(struct Jogador *vj, int n)
{
    int soma=0, i;
    for(i=0; i<n; i++)
    {
        soma += vj[i].qtdGols;
    }
    return soma/n;
}