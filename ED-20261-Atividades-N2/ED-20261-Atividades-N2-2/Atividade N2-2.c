#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
struct No {
    int valor;
    int altura; // incluído conforme modelo do professor
    struct No *esq;
    struct No *dir;
};

// Função para criar um novo nó
struct No* criarNo(int valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função recursiva para calcular altura
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

// Função para obter o fator de balanceamento
int obterFB(struct No* n) {
    if (n == NULL)
        return 0;

    int alturaEsq = calcularAltura(n->esq);
    int alturaDir = calcularAltura(n->dir);

    // FB = altura esquerda - altura direita
    return alturaEsq - alturaDir;
}

int main() {
    // Montagem manual da árvore: 20 -> 10 -> 5 -> 2
    struct No* raiz = criarNo(20);
    raiz->esq = criarNo(10);
    raiz->esq->esq = criarNo(5);
    raiz->esq->esq->esq = criarNo(2);

    // Cálculo do fator de balanceamento da raiz
    int fb = obterFB(raiz);

    // Exibição do resultado
    printf("Fator de Balanceamento da raiz (20): %d\n", fb);

    return 0;
}