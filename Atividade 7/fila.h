#ifndef FILA_H
#define FILA_H

// Definição da estrutura da fila
typedef struct Fila {
    int tamanho;
    int capacidade;
    int frente;
    int traseira;
    int *elementos;
} Fila;

// Protótipos das funções da fila
Fila *criarFila(int capacidade);
void destruirFila(Fila *fila);
int filaVazia(Fila *fila);
int filaCheia(Fila *fila);
void enfileirar(Fila *fila, int valor);
int desenfileirar(Fila *fila);

#endif