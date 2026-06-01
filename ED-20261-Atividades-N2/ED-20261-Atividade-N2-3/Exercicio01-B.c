/* RA: 2040482513038 - VINICIUS CARVALHO SANCHEZ */
#include <stdio.h>

int main()
{
    int v[] = {10,20,30,40,50};

    int *p = v;
    int soma = 0;

    while(p < v + 5)
    {
        printf("Valor: %d | Endereco: %p\n", *p, (void*)p);

        soma += *p;

        p++;
    }

    printf("\nSoma = %d\n", soma);

    return 0;
}
