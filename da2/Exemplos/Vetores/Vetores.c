#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[] = {1,1,2,3,5,8,13,21,34,55,89,144}, i, *vet;
    printf("v[0]: %d\n", v[0]);
    printf("v[1]: %d\n", v[1]);
    printf("v[2]: %d\n", v[2]);
    printf("v[5]: %d\n", v[5]);
    printf("v[8]: %d\n", v[8]);
    printf("v[9]: %d\n", v[9]);
    printf("v[11]: %d\n", v[11]);
    printf("v: %p\n", v);
    printf("*v: %d\n", *v);
    printf("&v[0]: %p\n", &v[0]);
    printf("&v[1]: %p\n", &v[1]);
    printf("&v[2]: %p\n", &v[2]);
    printf("*&v[0]: %d\n", *&v[0]);
    printf("*&v[1]: %d\n", *&v[1]);
    printf("*&v[2]: %d\n", *&v[2]);

    printf("*v: %d - v: %p\n", *v, v);
    printf("*v+1: %d - v+1: %p\n", *(v+1), v+1);
    printf("*v+2: %d - v+2: %p\n", *(v+2), v+2);
    printf("*v+3: %d - v+3: %p\n", *(v+3), v+3);
    printf("*v+4: %d - v+4: %p\n", *(v+4), v+4);
    printf("*v+5: %d - v+5: %p\n", *(v+5), v+5);


    printf("v: %p\n", v); // endereco base do vetor
    printf("*v: %d\n", *v); // apontado pelo endereco base do vetor <==> vetor[0]
    printf("&v: %p\n", &v); // endereco do endereco base do vetor (o vetor nao eh apontado por ninguem, portando o endereco dele mesmo)
    printf("*(&v): %p\n", *(&v)); // resolver o endereco de uma variavel eh igual a ela mesma! *(&v) = v
    printf("==>(&v)+1: %p\n", (&v)+1); // <==== ver (VISTO) ***
    // endereco do vetor deslocado de mais vetor, ou seja: (v + sizeof(v))
    // se fizer (&v)+1 - v = quantidade de bits ateh o primeiro endereco livre apos v. Dividido por 4 eh a quantidade de bytes ou o tamanho do vetor
    // ACREDITO QUE O MESMO NAO SE REPITA PARA UM VETOR ALOCADO DINAMICAMENTE, POIS &V tambem tera endereco, ou seja &V sera diferente de V (TESTAR!) **** TESTADO
    vet = (int*) malloc(12*sizeof(int));
    for(i=0; i<12; i++)
    {
        printf("v+i: %p - *v+i: %d\n", v+i, *(v+i)); // *(v+i) <==> v[i]
        vet[i] = i+1;
    }

    printf("vet[0]: %d\n", vet[0]);
    printf("vet[1]: %d\n", vet[1]);
    printf("vet[2]: %d\n", vet[2]);
    printf("vet[5]: %d\n", vet[5]);
    printf("vet[8]: %d\n", vet[8]);
    printf("vet[9]: %d\n", vet[9]);
    printf("vet[11]: %d\n", vet[11]);
    printf("vet: %p\n", vet);
    printf("*vet: %d\n", *vet);
    printf("&vet[0]: %p\n", &vet[0]);
    printf("&vet[1]: %p\n", &vet[1]);
    printf("&vet[2]: %p\n", &vet[2]);
    printf("*&vet[0]: %d\n", *&vet[0]);
    printf("*&vet[1]: %d\n", *&vet[1]);
    printf("*&vet[2]: %d\n", *&vet[2]);

    printf("*vet: %d - v: %p\n", *vet, vet);
    printf("*vet+1: %d - v+1: %p\n", *(vet+1), vet+1);
    printf("*vet+2: %d - v+2: %p\n", *(vet+2), vet+2);
    printf("*vet+3: %d - v+3: %p\n", *(vet+3), vet+3);
    printf("*vet+4: %d - v+4: %p\n", *(vet+4), vet+4);
    printf("*vet+5: %d - v+5: %p\n", *(vet+5), vet+5);


    printf("vet: %p\n", vet); // endereco base do vetor
    printf("*vet: %d\n", *vet); // apontado pelo endereco base do vetor <==> vetor[0]
    printf("&vet: %p\n", &vet); // endereco do endereco base do vetor (o vetor eh apontado um ponteiro que tem um endereco base)
    printf("*(&vet): %p\n", *(&vet)); // resolver o endereco de uma variavel eh igual a ela mesma! *(&vet) = vet
    printf("==>(&vet)+1: %p\n", (&vet)+1); // ACREDITO QUE O MESMO NAO SE REPITA PARA UM VETOR ALOCADO DINAMICAMENTE, POIS &V tambem tera endereco, ou seja &V sera diferente de V (TESTAR!) TESTADO****

    printf("sizeof(v)%ld\n", sizeof(v));
    printf("sizeof(int)%ld\n", sizeof(int));
    printf("sizeof(int*)%ld\n", sizeof(int*)); // no CS50 uma palavra tem 64 bits ****
    return 0;
}