/*PROGRAMA EXEMPLO PARA LEITURA ATEH EOF (END OF FILE)
  LER UMA SEQUENCIA DE NUMEROS INTEIROS ATEH EOF E APRESENTAR O SOMATORIO

  - Ao executar redirecionar a entrada. Exemplo:
    ./EOF.exe < Entrada

  - Para finalizar a execução iterativa teclar "Ctrl + D"

  */

#include <stdio.h>

int main()
{
    int soma=0, valor;
    while(scanf("%d", &valor) != EOF)
    {
        soma = soma + valor;
    }
    printf("%d\n", soma);
    return 0;
}