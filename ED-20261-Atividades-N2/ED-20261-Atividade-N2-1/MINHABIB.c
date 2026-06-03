/* RA: 2040482513038 - VINICIUS CARVALHO SANCHEZ */
#include <stdio.h>
#include "MINHABIB.h"

void imprimir_nos_internos(No* raiz) {
    if (raiz == NULL) return;

    if (raiz->esq != NULL || raiz->dir != NULL)
        printf("%d (%p) ", raiz->valor, (void*)raiz);

    imprimir_nos_internos(raiz->esq);
    imprimir_nos_internos(raiz->dir);
}

void imprimir_folhas(No* raiz) {
    if (raiz == NULL) return;

    if (raiz->esq == NULL && raiz->dir == NULL)
        printf("%d (%p) ", raiz->valor, (void*)raiz);

    imprimir_folhas(raiz->esq);
    imprimir_folhas(raiz->dir);
}

void imprimir_niveis(No* raiz, int nivel) {
    if (raiz == NULL) return;

    if (nivel == 0)
        printf("%d (%p) ", raiz->valor, (void*)raiz);
    else {
        imprimir_niveis(raiz->esq, nivel - 1);
        imprimir_niveis(raiz->dir, nivel - 1);
    }
}

int calcular_altura(No* no) {
    if (no == NULL) return -1;

    int esq = calcular_altura(no->esq);
    int dir = calcular_altura(no->dir);

    return (esq > dir ? esq : dir) + 1;
}

int calcular_profundidade(No* raiz, int valor, int nivel) {
    if (raiz == NULL) return -1;

    if (raiz->valor == valor)
        return nivel;

    if (valor < raiz->valor)
        return calcular_profundidade(raiz->esq, valor, nivel + 1);
    else
        return calcular_profundidade(raiz->dir, valor, nivel + 1);
}

void imprimir_ancestrais(No* raiz, int valor) {
    if (raiz == NULL) return;

    if (raiz->valor == valor) return;

    if ((raiz->esq && calcular_profundidade(raiz->esq, valor, 0) != -1) ||
        (raiz->dir && calcular_profundidade(raiz->dir, valor, 0) != -1)) {
        printf("%d ", raiz->valor);
    }

    if (valor < raiz->valor)
        imprimir_ancestrais(raiz->esq, valor);
    else
        imprimir_ancestrais(raiz->dir, valor);
}

void imprimir_descendentes(No* no) {
    if (no == NULL) return;

    if (no->esq) {
        printf("%d (%p) ", no->esq->valor, (void*)no->esq);
        imprimir_descendentes(no->esq);
    }

    if (no->dir) {
        printf("%d (%p) ", no->dir->valor, (void*)no->dir);
        imprimir_descendentes(no->dir);
    }
}

void analisar_arvore(No* raiz, int valorBusca) {
    printf("Raiz: %d (%p)\n", raiz->valor, (void*)raiz);

    printf("Nos internos: ");
    imprimir_nos_internos(raiz);
    printf("\n");

    printf("Folhas: ");
    imprimir_folhas(raiz);
    printf("\n");

    int altura = calcular_altura(raiz);

    for (int i = 0; i <= altura; i++) {
        printf("Nivel %d: ", i);
        imprimir_niveis(raiz, i);
        printf("\n");
    }

    No* atual = raiz;

    while (atual != NULL && atual->valor != valorBusca) {
        if (valorBusca < atual->valor)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    if (atual == NULL) {
        printf("Valor nao encontrado\n");
        return;
    }

    int grau = 0;
    if (atual->esq) grau++;
    if (atual->dir) grau++;

    printf("\nNo: %d (%p)\n", valorBusca, (void*)atual);
    printf("Grau: %d\n", grau);

    printf("Ancestrais: ");
    imprimir_ancestrais(raiz, valorBusca);
    printf("\n");

    printf("Descendentes: ");
    imprimir_descendentes(atual);
    printf("\n");

    printf("Altura: %d\n", calcular_altura(atual));
    printf("Profundidade: %d\n",
           calcular_profundidade(raiz, valorBusca, 0));

    printf("\nSubarvore:\n");

    int altSub = calcular_altura(atual);
    for (int i = 0; i <= altSub; i++) {
        printf("Nivel %d: ", i);
        imprimir_niveis(atual, i);
        printf("\n");
    }
}
