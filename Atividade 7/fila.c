#include "fila.h"
#include <stdlib.h>

Fila *criarFila(int capacidade) {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    fila->frente = 0;
    fila->traseira = -1;
    fila->elementos = (int *)malloc(capacidade * sizeof(int));
    return fila;
}

void destruirFila(Fila *fila) {
    free(fila->elementos);
    free(fila);
}

int filaVazia(Fila *fila) {
    return (fila->tamanho == 0);
}

int filaCheia(Fila *fila) {
    return (fila->tamanho == fila->capacidade);
}

void enfileirar(Fila *fila, int valor) {
    if (!filaCheia(fila)) {
        fila->traseira = (fila->traseira + 1) % fila->capacidade;
        fila->elementos[fila->traseira] = valor;
        fila->tamanho++;
    }
}

int desenfileirar(Fila *fila) {
    if (!filaVazia(fila)) {
        int valor = fila->elementos[fila->frente];
        fila->frente = (fila->frente + 1) % fila->capacidade;
        fila->tamanho--;
        return valor;
    }
    return -1; // Valor de erro, a fila está vazia
}