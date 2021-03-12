#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), m = atoi(argv[2]), i, sort;

    srand(time(NULL));

    printf("%d\n", n);
    for(i=0; i<m; i++)
    {
        sort = rand()%100;
        if(sort < 40) // 40% de I
        {
            printf("I %d\n", rand()%INT_MAX);
        }
        else if(sort < 80) // 40% de R
        {
            printf("R\n");
        }
        else // 20% de M
        {
            printf("M\n");
        }
    }
    printf("M");
    return 0;
}