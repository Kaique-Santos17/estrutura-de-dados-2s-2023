#ifndef PILHA_H
#define PILHA_H

// Definição da estrutura da pilha
typedef struct Pilha {
    int tamanho;
    int capacidade;
    int *elementos;
} Pilha;

// Protótipos das funções da pilha
Pilha *criarPilha(int capacidade);
void destruirPilha(Pilha *pilha);
int pilhaVazia(Pilha *pilha);
int pilhaCheia(Pilha *pilha);
void empilhar(Pilha *pilha, int valor);
int desempilhar(Pilha *pilha);

#endif