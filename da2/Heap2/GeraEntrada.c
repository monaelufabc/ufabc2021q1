#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), m = atoi(argv[2]), i, sort;

    printf("%d\n", n);
    srand(time(NULL));

    for(i=0; i<m; i++)
    {
        sort = rand()%100;
        if(sort < 40) // I
        {
            printf("I %d\n", rand()%INT_MAX);
        }
        else if(sort < 80) // R
        {
            printf("R\n");
        }
        else // M
        {
            printf("M\n");
        }
    }
    printf("M");
    return 0;
}