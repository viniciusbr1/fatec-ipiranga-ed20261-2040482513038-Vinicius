/* RA: 2040482513038 - VINICIUS CARVALHO SANCHEZ */
#include <stdio.h>

void trocar(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{
    int v[] = {10,20,30,40,50};

    int *inicio = v;
    int *fim = v + 4;

    while(inicio < fim)
    {
        trocar(inicio, fim);

        inicio++;
        fim--;
    }

    printf("Vetor invertido:\n");

    int *p = v;

    while(p < v + 5)
    {
        printf("%d ", *p);
        p++;
    }

    printf("\n");

    return 0;
}
