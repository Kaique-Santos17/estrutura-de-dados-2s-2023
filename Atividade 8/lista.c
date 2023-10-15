#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* lista_criar() {
    No* cabeca = (No*)malloc(sizeof(No));
    if (cabeca == NULL) {
        exit(1); // Tratamento de erro - você pode implementar melhor
    }
    cabeca->proximo = NULL;
    return cabeca;
}

void lista_destruir(No* L) {
    No* atual = L;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

void lista_inserir_fim(No* L, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        exit(1); // Tratamento de erro - você pode implementar melhor
    }
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    No* atual = L;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo_no;
}

void lista_imprimir(No* L) {
    No* atual = L->proximo;
    while (atual != NULL) {
        printf("%c ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int count = 0;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            count++;
        }
        atual = atual->proximo;
    }
    return count;
}

void lista_imprimir_inversa(No* L) {
    if (L->proximo == NULL) {
        return; // Lista vazia
    }
    No* atual = L->proximo;
    No* anterior = NULL;
    No* proximo = NULL;
    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }
    while (anterior != NULL) {
        printf("%c ", anterior->valor);
        atual = anterior->proximo;
        proximo = NULL;
        anterior->proximo = atual;
        anterior = proximo;
    }
    printf("\n");
}

void lista_inserir_no_i(No* L, int i, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        exit(1); // Tratamento de erro - você pode implementar melhor
    }
    novo_no->valor = valor;
    
    No* atual = L;
    int pos = 0;
    while (pos < i && atual->proximo != NULL) {
        atual = atual->proximo;
        pos++;
    }
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

void lista_remover_no_i(No* L, int i) {
    No* atual = L;
    int pos = 0;
    while (pos < i && atual->proximo != NULL) {
        atual = atual->proximo;
        pos++;
    }
    if (atual->proximo != NULL) {
        No* no_remover = atual->proximo;
        atual->proximo = no_remover->proximo;
        free(no_remover);
    }
}

void lista_remover_no(No* L, char valor_busca) {
    No* atual = L;
    while (atual->proximo != NULL) {
        if (atual->proximo->valor == valor_busca) {
            No* no_remover = atual->proximo;
            atual->proximo = no_remover->proximo;
            free(no_remover);
        } else {
            atual = atual->proximo;
        }
    }
}

