#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char *geraNome(int);

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), i, m, j;
    char *nome;
    srand(time(NULL));
    printf("%d\n", n);

    for(i=0; i<n; i++)
    {
        nome = geraNome((rand()%26)+5);
        printf("%s\n", nome);
        free(nome);
        m = (rand()%40)+11;
        printf("%d\n", m);
        for(j=0; j<m; j++)
        {
            nome = geraNome((rand()%26)+5);
            printf("%s %d%s", nome, rand()%101, (i==n-1 && j==m-1?"":"\n"));
            free(nome);
        }
    }
    return 0;
}

char *geraNome(int n)
{
    char *str = (char*) malloc( (n+3) * sizeof(char));
    int i;
    for(i=0; i<n; i++)
    {
        do
        {
            str[i] = rand()%256;
        }while(!isalpha(str[i]));
        str[i] = tolower(str[i]);
    }
    str[i] = '\0';
    return str;
}