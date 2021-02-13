#include <stdio.h>
#include <stdlib.h>

struct aluno
{
    char nome[50];
    int idade, qtNotas;
    float *notas;
};

int main()
{
    int n, i, j;
    struct aluno *turma;

    scanf("%d", &n);
    turma = (struct aluno*) malloc(n * sizeof(struct aluno));

    for(i=0; i<n; i++)
    {
        scanf("%s %d %d", &turma[i].nome, &turma[i].idade, &turma[i].qtNotas);
        turma[i].notas = (float*) malloc(turma[i].qtNotas * sizeof(float));
        for(j=0; j<turma[i].qtNotas; j++)
        {
            scanf("%f", &turma[i].notas[j]);
        }
    }

    for(i=0; i<n; i++)
    {
        printf("%s %d\n", turma[i].nome, turma[i].idade);
        for(j=0; j<turma[i].qtNotas; j++)
        {
            printf("%f ", turma[i].notas[j]);
        }
        printf("\n");
    }
    return 0;
}