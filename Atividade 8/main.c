#include <stdio.h>
#include "lista.h"

int main() {
    No* lista = lista_criar();

    lista_inserir_fim(lista, 'A');
    lista_inserir_fim(lista, 'B');
    lista_inserir_fim(lista, 'C');
    lista_inserir_fim(lista, 'A');
    lista_inserir_fim(lista, 'D');

    printf("Lista: ");
    lista_imprimir(lista);

    char busca = 'A';
    printf("Existe %c na lista? %d\n", busca, lista_verificar_existencia(lista, busca));
    printf("Ocorrencias de %c na lista: %d\n", busca, lista_verificar_ocorrencias(lista, busca));

    printf("Lista invertida: ");
    lista_imprimir_inversa(lista);

    lista_inserir_no_i(lista, 2, 'E');
    printf("Inserindo 'E' na posição 2: ");
    lista_imprimir(lista);

    lista_remover_no_i(lista, 3);
    printf("Removendo elemento na posição 3: ");
    lista_imprimir(lista);

    char valor_remover = 'A';
    lista_remover_no(lista, valor_remover);
    printf("Removendo todos os elementos %c: ", valor_remover);
    lista_imprimir(lista);

    lista_destruir(lista);

    return 0;
}