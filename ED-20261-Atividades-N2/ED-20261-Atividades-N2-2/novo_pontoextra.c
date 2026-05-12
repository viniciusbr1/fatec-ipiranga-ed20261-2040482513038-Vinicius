#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    int altura;
    struct No *esq;
    struct No *dir;
};

// cria nó
struct No* criarNo(int valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}


int calcularAltura(struct No* n) {

    if (n == NULL) {
        printf("Chegou em NULL -> altura = -1\n");
        return -1;
    }

    printf("Calculando altura do nó %d\n", n->valor);

    int alturaEsq = calcularAltura(n->esq);
    int alturaDir = calcularAltura(n->dir);

    int alturaFinal;

    if (alturaEsq > alturaDir)
        alturaFinal = 1 + alturaEsq;
    else
        alturaFinal = 1 + alturaDir;

    printf("Nó %d -> altura esquerda: %d | altura direita: %d | altura final: %d\n",
           n->valor, alturaEsq, alturaDir, alturaFinal);

    return alturaFinal;
}


int obterFB(struct No* n) {

    if (n == NULL)
        return 0;

    printf("\n=== Calculando FB do nó %d ===\n", n->valor);

    int alturaEsq = calcularAltura(n->esq);
    int alturaDir = calcularAltura(n->dir);

    int fb = alturaEsq - alturaDir;

    printf("FB do nó %d = %d - %d = %d\n",
           n->valor, alturaEsq, alturaDir, fb);

    return fb;
}

int main() {


    struct No* raiz = criarNo(20);
    raiz->esq = criarNo(10);
    raiz->esq->esq = criarNo(5);
    raiz->esq->esq->esq = criarNo(2);

    printf("=== INICIO DO CALCULO DA ARVORE ===\n");

    int fb = obterFB(raiz);

    printf("\nRESULTADO FINAL:\n");
    printf("Fator de Balanceamento da raiz (20): %d\n", fb);

    return 0;
}
