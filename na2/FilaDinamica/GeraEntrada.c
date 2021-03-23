#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), i, sort;

    srand(time(NULL));
    for(i=0; i<n; i++)
    {
        sort = rand()%100;
        if(sort < 40)
        {
            printf("E %d\n", rand()%INT_MAX);
        }
        else if(sort < 80)
        {
            printf("D\n");
        }
        else // 20%
        {
            printf("M\n");
        }
    }
    printf("D");
    return 0;
}