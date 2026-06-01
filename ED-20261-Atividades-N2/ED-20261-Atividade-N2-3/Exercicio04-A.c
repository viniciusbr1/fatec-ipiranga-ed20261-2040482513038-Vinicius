#include <stdio.h>

int buscaBinaria(int *vet, int inicio, int fim, int alvo, int *chamadas)
{
    (*chamadas)++;

    if (inicio > fim)
    {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (*(vet + meio) == alvo)
    {
        return meio;
    }

    if (*(vet + meio) > alvo)
    {
        return buscaBinaria(vet, inicio, meio - 1, alvo, chamadas);
    }

    return buscaBinaria(vet, meio + 1, fim, alvo, chamadas);
}

int main(void)
{
    int dados[] = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};
    int tamanho = 10;

    int alvos[] = {23, 50, 2};

    for (int i = 0; i < 3; i++)
    {
        int chamadas = 0;
        int resultado = buscaBinaria(dados, 0, tamanho - 1, alvos[i], &chamadas);

        if (resultado != -1)
        {
            printf("Valor %d encontrado no indice %d\n", alvos[i], resultado);
        }
        else
        {
            printf("Valor %d nao encontrado\n", alvos[i]);
        }

        printf("Chamadas recursivas: %d\n\n", chamadas);
    }

    return 0;
}