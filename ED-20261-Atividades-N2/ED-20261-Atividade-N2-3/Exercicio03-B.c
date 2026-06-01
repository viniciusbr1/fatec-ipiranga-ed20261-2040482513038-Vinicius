#include <stdio.h>

int movimentos = 0;

void hanoi(int n, char origem, char destino, char auxiliar)
{
    if (n == 1)
    {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        movimentos++;
        return;
    }

    hanoi(n - 1, origem, auxiliar, destino);
    printf("Mover disco %d de %c para %c\n", n, origem, destino);
    movimentos++;
    hanoi(n - 1, auxiliar, destino, origem);
}

int potencia2(int n)
{
    int resultado = 1;

    for (int i = 0; i < n; i++)
    {
        resultado *= 2;
    }

    return resultado;
}

int main(void)
{
    for (int n = 1; n <= 6; n++)
    {
        movimentos = 0;

        printf("\nTeste com n = %d\n", n);
        hanoi(n, 'A', 'C', 'B');

        printf("Movimentos contados: %d\n", movimentos);
        printf("Movimentos esperados: %d\n", potencia2(n) - 1);
    }

    /*
        n   Movimentos contado   2^n - 1 esperado
        1   1                    1
        2   3                    3
        3   7                    7
        4   15                   15
        5   31                   31
        6   63                   63

        Complexidade: O(2^n)
    */

    return 0;
}