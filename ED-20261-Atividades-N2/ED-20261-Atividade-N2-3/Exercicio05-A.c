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

    printf("Arvore criada com sucesso.\n");
    printf("Altura da raiz: %d\n", alturaNo(raiz));
    printf("Profundidade do no 45: %d\n", profundidadeNo(raiz, 45, 0));
    printf("Grau da raiz: %d\n", grauNo(raiz));

    liberarArvore(raiz);

    return 0;
}
