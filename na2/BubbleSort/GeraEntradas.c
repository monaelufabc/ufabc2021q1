#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(int argc, char **argv)
{
    int t = atoi(argv[1]), k, n, i;
    srand(time(NULL));
    for(k=0; k<t; k++)
    {
        n = (rand()%9996)+5; // min:5 max:10000
        printf("%d\n", n);
        for(i=0; i<n; i++)
        {
            printf("%d%s", rand()%INT_MAX, (i<n-1?" ":(k<t-1?"\n":"")));
        }
    }
    return 0;
}