#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int topo = -1;
char pilha[MAX];

void push(char c) {
    if (topo == MAX - 1) {
        printf("Erro: pilha cheia\n");
        exit(EXIT_FAILURE);
    }
    topo++;
    pilha[topo] = c;
}

char pop() {
    if (topo == -1) {
        printf("Erro: pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    char c = pilha[topo];
    topo--;
    return c;
}

int verifica_palindromo(char* string) {
    int tamanho = strlen(string);
    for (int i = 0; i < tamanho; i++) {
        push(string[i]);
    }
    for (int i = 0; i < tamanho; i++) {
        if (string[i] != pop()) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char string[MAX];
    printf("Digite uma string: ");
    scanf("%s", string);
    if (verifica_palindromo(string)) {
        printf("A string é um palíndromo\n");
    } else {
        printf("A string não é um palíndromo\n");
    }
    return 0;
}
