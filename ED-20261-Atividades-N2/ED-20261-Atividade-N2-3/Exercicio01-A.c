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
    int x = 10;
    int y = 20;

    printf("Antes da troca:\n");
    printf("x = %d | endereco = %p\n", x, (void*)&x);
    printf("y = %d | endereco = %p\n", y, (void*)&y);

    trocar(&x, &y);

    printf("\nDepois da troca:\n");
    printf("x = %d | endereco = %p\n", x, (void*)&x);
    printf("y = %d | endereco = %p\n", y, (void*)&y);

    return 0;
}
