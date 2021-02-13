#include<stdio.h>

int main()
{
    int v[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000}, i;

    printf("v[0]: %d\n", v[0]);
    printf("v[5]: %d\n", v[5]);
    printf("v[9]: %d\n", v[9]);

    printf("v: %p\n", v);
    printf("&v[0]: %p\n", &v[0]);
    printf("*v: %d\n", *v);
    printf("\n\nv: %p -> *v: %d\n", v, *v);
    printf("v+1: %p -> &v[1]: %p -> *v+1: %d\n", v+1, &v[1], *(v+1));
    printf("v+2: %p -> &v[2]: %p -> *v+2: %d\n", v+2, &v[2], *(v+2));
    printf("v+3: %p -> &v[3]: %p -> *v+3: %d\n", v+3, &v[3], *(v+3));
    printf("v+4: %p -> &v[4]: %p -> *v+4: %d\n", v+4, &v[4], *(v+4));
    printf("v+5: %p -> &v[5]: %p -> *v+5: %d\n", v+5, &v[5], *(v+5));
    printf("v+9: %p -> &v[9]: %p -> *v+9: %d\n", v+9, &v[9], *(v+9));

    for(i=0; i<10; i++)
    {
        printf("*(v+%d): %d\n", i, *(v+i)); // *(v+i) <==> v[i]  []
    }

    return 0;
}