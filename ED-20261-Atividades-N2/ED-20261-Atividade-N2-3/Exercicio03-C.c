#include <stdio.h>

int movimentos = 0;

void imprimirEspacos(int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        printf(" ");
    }
}

void hanoi(int n, char origem, char destino, char auxiliar, int nivel)
{
    if (n == 1)
    {
        imprimirEspacos(nivel * 2);
        printf("Nivel %d: mover disco 1 de %c para %c\n", nivel, origem, destino);
        movimentos++;
        return;
    }

    hanoi(n - 1, origem, auxiliar, destino, nivel + 1);

    imprimirEspacos(nivel * 2);
    printf("Nivel %d: mover disco %d de %c para %c\n", nivel, n, origem, destino);
    movimentos++;

    hanoi(n - 1, auxiliar, destino, origem, nivel + 1);
}

int main(void)
{
    int testes[] = {1, 3, 4};

    for (int i = 0; i < 3; i++)
    {
        movimentos = 0;

        printf("\nTeste com n = %d\n", testes[i]);
        hanoi(testes[i], 'A', 'C', 'B', 0);

        printf("Total de movimentos: %d\n", movimentos);
    }

    return 0;
}