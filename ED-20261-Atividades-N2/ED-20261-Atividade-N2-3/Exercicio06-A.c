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
    if (raiz == NULL || raiz->dado == valor)
    {
        return raiz;
    }

    if (valor < raiz->dado)
    {
        return buscar(raiz->esq, valor);
    }

    return buscar(raiz->dir, valor);
}

void imprimirAncestral(No *raiz, int valor)
{
    if (raiz == NULL || raiz->dado == valor)
    {
        return;
    }

    if (valor < raiz->dado)
    {
        imprimirAncestral(raiz->esq, valor);
        printf("%d ", raiz->dado);
    }
    else
    {
        imprimirAncestral(raiz->dir, valor);
        printf("%d ", raiz->dado);
    }
}

void imprimirSubarvoreEmOrdem(No *no)
{
    if (no == NULL)
    {
        return;
    }

    imprimirSubarvoreEmOrdem(no->esq);
    printf("%d ", no->dado);
    imprimirSubarvoreEmOrdem(no->dir);
}

void imprimirDescendentes(No *raiz, int valor)
{
    No *no = buscar(raiz, valor);

    if (no == NULL)
    {
        printf("Valor nao encontrado");
        return;
    }

    imprimirSubarvoreEmOrdem(no->esq);
    imprimirSubarvoreEmOrdem(no->dir);
}

int contarNos(No *no)
{
    if (no == NULL)
    {
        return 0;
    }

    return 1 + contarNos(no->esq) + contarNos(no->dir);
}

int contarDescendentes(No *no)
{
    if (no == NULL)
    {
        return 0;
    }

    return contarNos(no->esq) + contarNos(no->dir);
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

    for (int i = 0; i < 11; i++)
    {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Ancestrais do no 30: ");
    imprimirAncestral(raiz, 30);

    printf("\nDescendentes do no 30: ");
    imprimirDescendentes(raiz, 30);

    No *no30 = buscar(raiz, 30);
    printf("\nQuantidade de descendentes do no 30: %d\n", contarDescendentes(no30));

    liberarArvore(raiz);

    return 0;
}