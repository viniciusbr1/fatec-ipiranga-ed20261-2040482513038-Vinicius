#include <stdio.h>

float calcularMedia(float *vet, int n)
{
    float soma = 0.0f;
    float *ptr = vet;

    for (int i = 0; i < n; i++)
    {
        soma += *ptr;
        ptr++;
    }

    return soma / n;
}

void encontrarExtremos(float *vet, int n, float *maior, float *menor)
{
    float *ptr = vet;

    *maior = *ptr;
    *menor = *ptr;

    ptr++;

    for (int i = 1; i < n; i++)
    {
        if (*ptr > *maior)
        {
            *maior = *ptr;
        }

        if (*ptr < *menor)
        {
            *menor = *ptr;
        }

        ptr++;
    }
}

void normalizar(float *vet, int n)
{
    float maior;
    float menor;

    encontrarExtremos(vet, n, &maior, &menor);

    float *ptr = vet;

    for (int i = 0; i < n; i++)
    {
        *ptr = *ptr / maior;
        ptr++;
    }
}

void imprimirVetor(float *vet, int n, const char *titulo)
{
    float *ptr = vet;

    printf("\n%s\n", titulo);

    for (int i = 0; i < n; i++)
    {
        printf("%.4f ", *ptr);
        ptr++;
    }

    printf("\n");
}

int main()
{
    float notas[] = {7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f};
    int n = 6;

    float media;
    float maior;
    float menor;

    imprimirVetor(notas, n, "Vetor antes da normalizacao:");

    media = calcularMedia(notas, n);

    encontrarExtremos(notas, n, &maior, &menor);

    printf("\nMedia: %.4f\n", media);
    printf("Maior valor: %.4f\n", maior);
    printf("Menor valor: %.4f\n", menor);

    normalizar(notas, n);

    imprimirVetor(notas, n, "Vetor depois da normalizacao:");

    return 0;
}