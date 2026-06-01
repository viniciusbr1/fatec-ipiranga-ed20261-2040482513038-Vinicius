/* RA: 2040482513038 - VINICIUS CARVALHO SANCHEZ */
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *esq;
    struct No *dir;
} No;

No *inserir(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        No *novo = malloc(sizeof(No));

        if (novo == NULL)
        {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }

        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    if (valor < raiz->dado)
    {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if (valor > raiz->dado)
    {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

No *buscar(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (raiz->dado == valor)
    {
        return raiz;
    }

    if (valor < raiz->dado)
    {
        return buscar(raiz->esq, valor);
    }

    return buscar(raiz->dir, valor);
}

int alturaNo(No *no)
{
    if (no == NULL)
    {
        return -1;
    }

    int alturaEsq = alturaNo(no->esq);
    int alturaDir = alturaNo(no->dir);

    if (alturaEsq > alturaDir)
    {
        return alturaEsq + 1;
    }

    return alturaDir + 1;
}

int profundidadeNo(No *raiz, int valor, int prof)
{
    if (raiz == NULL)
    {
        return -1;
    }

    if (raiz->dado == valor)
    {
        return prof;
    }

    if (valor < raiz->dado)
    {
        return profundidadeNo(raiz->esq, valor, prof + 1);
    }

    return profundidadeNo(raiz->dir, valor, prof + 1);
}

int grauNo(No *no)
{
    int grau = 0;

    if (no == NULL)
    {
        return -1;
    }

    if (no->esq != NULL)
    {
        grau++;
    }

    if (no->dir != NULL)
    {
        grau++;
    }

    return grau;
}

void liberarArvore(No *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main(void)
{
    No *raiz = NULL;

    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    int tamanho = 11;

    for (int i = 0; i < tamanho; i++)
    {
        raiz = inserir(raiz, valores[i]);
    }

    /*
                    50
                  /    \
                30      70
               /  \    /  \
             20   40  60  80
            / \     \   \
          10  25    45  65

        Verificacao manual:

        No 50:
        Altura = 3
        Profundidade = 0
        Grau = 2

        No 30:
        Altura = 2
        Profundidade = 1
        Grau = 2

        No 10:
        Altura = 0
        Profundidade = 3
        Grau = 0
    */

    No *no50 = buscar(raiz, 50);
    No *no30 = buscar(raiz, 30);
    No *no10 = buscar(raiz, 10);

    printf("Verificacao do no 50:\n");
    printf("Altura: %d\n", alturaNo(no50));
    printf("Profundidade: %d\n", profundidadeNo(raiz, 50, 0));
    printf("Grau: %d\n\n", grauNo(no50));

    printf("Verificacao do no 30:\n");
    printf("Altura: %d\n", alturaNo(no30));
    printf("Profundidade: %d\n", profundidadeNo(raiz, 30, 0));
    printf("Grau: %d\n\n", grauNo(no30));

    printf("Verificacao do no 10:\n");
    printf("Altura: %d\n", alturaNo(no10));
    printf("Profundidade: %d\n", profundidadeNo(raiz, 10, 0));
    printf("Grau: %d\n", grauNo(no10));

    liberarArvore(raiz);

    return 0;
}
