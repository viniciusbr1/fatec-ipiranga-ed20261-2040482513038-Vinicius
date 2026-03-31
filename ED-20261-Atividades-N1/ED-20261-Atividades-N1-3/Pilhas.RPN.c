// AUTOR: Vinicius Carvalho Sanchez
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// === PILHA ===

// Quantidade máxima de elementos que a pilha pode armazenar
#define MAX 4

// Estrutura da pilha usando vetor
int pilha[MAX];

// Marca a posição do elemento que está no topo
// Inicia com -1 para indicar que a pilha está vazia
int topo = -1;

// Insere um novo valor no topo da pilha
void push(int valor) {
    // Confere se ainda existe espaço disponível
    if (topo == MAX - 1) {
        printf("Erro: pilha cheia!\n");
        exit(1);
    }

    // Avança o topo e guarda o valor
    pilha[++topo] = valor;
}

// Retira o elemento que está no topo da pilha
int pop() {
    // Confere se há algum elemento para remover
    if (topo == -1) {
        printf("Erro: pilha vazia!\n");
        exit(1);
    }

    // Devolve o valor do topo e reduz a posição
    return pilha[topo--];
}

// Exibe todos os valores armazenados atualmente na pilha
void mostrar() {
    // Caso não exista nenhum elemento
    if (topo == -1) {
        printf("Pilha vazia\n");
        return;
    }

    // Mostra os elementos da base até o topo
    printf("Pilha: ");
    for (int i = 0; i <= topo; i++) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

// Exibe somente o valor que está no topo
void mostrarTopo() {
    // Caso a pilha não tenha elementos
    if (topo == -1) {
        printf("Topo: pilha vazia\n");
    } else {
        printf("Topo: %d\n", pilha[topo]);
    }
}

// === EXPRESSÃO PÓS-FIXA ===

// Verifica se o caractere lido é um operador aceito
int Operador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Executa a operação entre dois valores
int calcular(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Função principal do programa
int main() {

    // Vetor que guarda a expressão digitada pelo usuário
    char expr[100];

    // Solicita a expressão
    printf("Digite a expressao pos-fixa (ex: 34+2*): ");
    scanf("%99s", expr);

    // Variável usada para percorrer a string
    int i = 0;

    // Lê a expressão enquanto não chegar ao final
    while (expr[i] != '\0') {

        printf("\nProcessando: %c\n", expr[i]);

        // Quando o caractere for um número
        if (isdigit(expr[i])) {

            // Converte de caractere para inteiro
            int valor = expr[i] - '0';

            printf("Push(Adicionar): %d\n", valor);

            // Coloca o número na pilha
            push(valor);
        }

        // Quando o caractere for um operador
        else if (Operador(expr[i])) {

            // É necessário ter pelo menos dois números empilhados
            if (topo < 1) {
                printf("Expressao invalida!\n");
                return 1;
            }

            // Retira os dois últimos valores inseridos
            int b = pop();
            int a = pop();

            // Mostra qual conta será feita
            printf("Operacao: %d %c %d\n", a, expr[i], b);

            // Faz o cálculo
            int resultado = calcular(a, b, expr[i]);

            printf("Resultado parcial: %d\n", resultado);

            // Guarda o resultado de volta na pilha
            push(resultado);
        }

        // Caso apareça algo que não seja número nem operador
        else {
            printf("Expressao invalida!\n");
            return 1;
        }

        // Exibe a situação atual da pilha
        mostrar();
        mostrarTopo();

        // Passa para o próximo caractere
        i++;
    }

    // === CONFERÊNCIA FINAL ===

    // No final deve restar somente um valor
    if (topo != 0) {
        printf("Expressao invalida!\n");
    } 
    else {
        // Esse valor restante é o resultado final
        printf("\nResultado final: %d\n", pop());
    }

    return 0;
}
