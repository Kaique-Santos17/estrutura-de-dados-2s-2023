#include "pilha.h"
#include <stdlib.h>

Pilha *criarPilha(int capacidade) {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->tamanho = 0;
    pilha->capacidade = capacidade;
    pilha->elementos = (int *)malloc(capacidade * sizeof(int));
    return pilha;
}

void destruirPilha(Pilha *pilha) {
    free(pilha->elementos);
    free(pilha);
}

int pilhaVazia(Pilha *pilha) {
    return (pilha->tamanho == 0);
}

int pilhaCheia(Pilha *pilha) {
    return (pilha->tamanho == pilha->capacidade);
}

void empilhar(Pilha *pilha, int valor) {
    if (!pilhaCheia(pilha)) {
        pilha->elementos[pilha->tamanho++] = valor;
    }
}

int desempilhar(Pilha *pilha) {
    if (!pilhaVazia(pilha)) {
        return pilha->elementos[--pilha->tamanho];
    }
    return -1; // Valor de erro, a pilha está vazia
}