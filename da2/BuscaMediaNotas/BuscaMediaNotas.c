#include <stdio.h>
#include <stdlib.h>
struct Aluno
{
    char nome[105];
    char matricula[14];
    int qtNotas;
    int *notas;
};

int calculaMediaInteira(int *, int);

int main()
{
    struct Aluno *turma;
    int n, i, j, media;

    scanf("%d", &n);
    turma = (struct Aluno*) malloc(n * sizeof(struct Aluno));

    for(i=0; i<n; i++)
    {
        scanf("%s", turma[i].nome);
        scanf("%s", turma[i].matricula);
        scanf("%d", &turma[i].qtNotas);
        turma[i].notas = (int*) malloc(turma[i].qtNotas * sizeof(int));
        for(j=0; j<turma[i].qtNotas; j++)
        {
            scanf("%d", &turma[i].notas[j]);
        }
    }

    scanf("%d", &media);

    for(i=0; i<n; i++)
    {
        if(calculaMediaInteira(turma[i].notas, turma[i].qtNotas) >= media)
        {
            printf("[%s] %s\n", turma[i].matricula, turma[i].nome);
        }
    }
}

int calculaMediaInteira(int *v, int n)
{
    int i, soma = 0;
    for(i=0; i<n; i++)
    {
        soma += v[i];
    }
    return soma/n;
}