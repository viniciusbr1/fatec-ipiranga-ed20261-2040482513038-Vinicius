/* RA: 2040482513038 - VINICIUS CARVALHO SANCHEZ */
#include <stdio.h>

long long potenciaRapida(long long base, int exp, int *chamadas)
{
    (*chamadas)++;

    if (exp == 0)
    {
        return 1;
    }

    if (exp % 2 == 0)
    {
        long long metade = potenciaRapida(base, exp / 2, chamadas);
        return metade * metade;
    }

    return base * potenciaRapida(base, exp - 1, chamadas);
}

long long potenciaIngenua(long long base, int exp, int *chamadas)
{
    (*chamadas)++;

    if (exp == 0)
    {
        return 1;
    }

    return base * potenciaIngenua(base, exp - 1, chamadas);
}

int main(void)
{
    long long bases[] = {2, 3, 5, 7};
    int expoentes[] = {10, 7, 0, 12};

    for (int i = 0; i < 4; i++)
    {
        int chamadasRapida = 0;
        int chamadasIngenua = 0;

        long long resultadoRapida = potenciaRapida(bases[i], expoentes[i], &chamadasRapida);
        long long resultadoIngenua = potenciaIngenua(bases[i], expoentes[i], &chamadasIngenua);

        printf("%lld^%d = %lld\n", bases[i], expoentes[i], resultadoRapida);
        printf("Chamadas potencia rapida: %d\n", chamadasRapida);
        printf("Chamadas potencia ingenua: %d\n\n", chamadasIngenua);

        (void)resultadoIngenua;
    }

    /*
        Caso base:
        Quando exp == 0, a funcao retorna 1.

        Caso recursivo da potencia rapida:
        Se o expoente for par, calcula base^(exp/2) uma vez
        e multiplica o resultado por ele mesmo.

        Se o expoente for impar, calcula base * base^(exp-1).

        Comparacao:
        A potencia ingenua faz uma chamada para cada reducao de 1 no expoente,
        entao possui complexidade O(n).

        A potencia rapida divide o expoente pela metade quando ele eh par,
        por isso possui complexidade O(log n).
    */

    return 0;
}
