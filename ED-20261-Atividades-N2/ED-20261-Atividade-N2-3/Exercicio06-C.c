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

void relatorioNo(No *raiz, int valor)
{
    No *no = buscar(raiz, valor);

    if (no == NULL)
    {
        printf("Erro: valor %d nao encontrado na arvore.\n", valor);
        return;
    }

    printf("+----------------------------------+\n");
    printf("| RELATORIO DO NO: %-15d|\n", valor);
    printf("+----------------------------------+\n");
    printf("| Profundidade : %-17d|\n", profundidadeNo(raiz, valor, 0));
    printf("| Altura       : %-17d|\n", alturaNo(no));
    printf("| Grau         : %-17d|\n", grauNo(no));

    printf("| Ancestrais   : ");
    if (valor == raiz->dado)
    {
        printf("nenhum");
    }
    else
    {
        imprimirAncestral(raiz, valor);
    }
    printf("\n");

    printf("| Descendentes : ");
    if (contarDescendentes(no) == 0)
    {
        printf("nenhum");
    }
    else
    {
        imprimirDescendentes(raiz, valor);
    }
    printf("\n");

    printf("| Qtd Descend. : %-17d|\n", contarDescendentes(no));
    printf("+----------------------------------+\n\n");
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

    relatorioNo(raiz, 50);
    relatorioNo(raiz, 30);
    relatorioNo(raiz, 10);
    relatorioNo(raiz, 70);

    liberarArvore(raiz);

    return 0;
}