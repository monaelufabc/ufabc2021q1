#include <stdio.h>

int fibonacci(int);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
    return 0;
}

int fibonacci(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-2) + fibonacci(n-1);
    }
}