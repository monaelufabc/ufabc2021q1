#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char *geraNome(int);
char *geraMatricula(int);

int main(int argc, char** argv)
{
    int i, j, n = atoi(argv[1]), m;
    char *pNome, *pMatr;

    srand(time(NULL));
    printf("%d\n", n);

    for(i=0; i<n; i++)
    {
        pNome = geraNome((rand()%91)+5);
        pMatr = geraMatricula(11);
        printf("%s\n", pNome);
        printf("%s\n", pMatr);
        free(pNome);
        free(pMatr);
        m = (rand()%10)+1;
        printf("%d\n", m);
        for(j=0; j<m; j++)
        {
            printf("%d%s", rand()%10, (j<m-1?" ":"\n"));
        }
    }
    printf("%d\n", rand()%10);

    return 0;
}

char *geraNome(int n)
{
    char *str = (char*) malloc((n+3) * sizeof(char));
    int i;
    for(i=0; i<n; i++)
    {
        do
        {
            str[i] = rand()%256;
        }while(!isalpha(str[i]));
    }
    str[i] = 0;
    return str;
}

char *geraMatricula(int n)
{
    char *str = (char*) malloc((n+3) * sizeof(char));
    int i;
    for(i=0; i<n; i++)
    {
        do
        {
            str[i] = rand()%256;
        }while(!isdigit(str[i]));
    }
    str[i] = 0;
    return str;
}