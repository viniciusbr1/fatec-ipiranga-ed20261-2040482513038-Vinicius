#include <stdio.h>
#include <stdlib.h>


struct No {
    int valor;
    int altura; 
    struct No *esq;
    struct No *dir;
};


struct No* criarNo(int valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}


int calcularAltura(struct No* n) {
    // Caso base
    if (n == NULL)
        return -1;

    int alturaEsq = calcularAltura(n->esq);
    int alturaDir = calcularAltura(n->dir);

    // Retorna 1 + maior altura
    if (alturaEsq > alturaDir)
        return 1 + alturaEsq;
    else
        return 1 + alturaDir;
}


int obterFB(struct No* n) {
    if (n == NULL)
        return 0;

    int alturaEsq = calcularAltura(n->esq);
    int alturaDir = calcularAltura(n->dir);

    return alturaEsq - alturaDir;
}

int main() {
    // Montagem manual da árvore: 20 -> 10 -> 5 -> 2
    struct No* raiz = criarNo(20);
    raiz->esq = criarNo(10);
    raiz->esq->esq = criarNo(5);
    raiz->esq->esq->esq = criarNo(2);

  
    int fb = obterFB(raiz);

   
    printf("Fator de Balanceamento da raiz (20): %d\n", fb);

    return 0;
}
