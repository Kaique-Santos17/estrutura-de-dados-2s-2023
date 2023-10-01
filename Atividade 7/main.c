#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main() {
    // Caso de uso para Pilha
    Pilha *pilha = criarPilha(5);
    empilhar(pilha, 1);
    empilhar(pilha, 2);
    empilhar(pilha, 3);

    printf("Elementos desempilhados da pilha: %d, %d, %d\n", desempilhar(pilha), desempilhar(pilha), desempilhar(pilha));
    destruirPilha(pilha);

    // Caso de uso para Fila
    Fila *fila = criarFila(5);
    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);

    printf("Elementos desenfileirados da fila: %d, %d, %d\n", desenfileirar(fila), desenfileirar(fila), desenfileirar(fila));
    destruirFila(fila);

    return 0;
}