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

void imprimirGrausEmOrdem(No *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    imprimirGrausEmOrdem(raiz->esq);
    printf("No %d - Grau: %d\n", raiz->dado, grauNo(raiz));
    imprimirGrausEmOrdem(raiz->dir);
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

    int nosAltura[] = {50, 30, 70, 20, 10};

    printf("Altura dos nos:\n");
    for (int i = 0; i < 5; i++)
    {
        No *noEncontrado = buscar(raiz, nosAltura[i]);
        printf("Altura do no %d: %d\n", nosAltura[i], alturaNo(noEncontrado));
    }

    int nosProfundidade[] = {50, 30, 70, 45, 10};

    printf("\nProfundidade dos nos:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Profundidade do no %d: %d\n",
               nosProfundidade[i],
               profundidadeNo(raiz, nosProfundidade[i], 0));
    }

    printf("\nGrau de cada no em ordem:\n");
    imprimirGrausEmOrdem(raiz);

    printf("\nAltura total da arvore: %d\n", alturaNo(raiz));

    liberarArvore(raiz);

    return 0;
}