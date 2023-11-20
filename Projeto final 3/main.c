#include <stdio.h>
#include "arvorebinaria.h"

int main() {
    TreeNode* root = NULL;

    // Inserção
    root = inserir(root, 50);
    root = inserir(root, 30);
    root = inserir(root, 20);
    root = inserir(root, 40);
    root = inserir(root, 70);
    root = inserir(root, 60);
    root = inserir(root, 80);

    // Teste de busca
    printf("Busca por 20: %s\n", buscar(root, 20) ? "Encontrado" : "Não encontrado");
    printf("Busca por 90: %s\n", buscar(root, 90) ? "Encontrado" : "Não encontrado");

    // Teste de remoção
    printf("Removendo 20\n");
    root = remover(root, 20);
    printf("Busca por 20: %s\n", buscar(root, 20) ? "Encontrado" : "Não encontrado");

    // Percursos na árvore
    printf("Percorrendo em pré-ordem: ");
    percorrerPreOrdem(root);
    printf("\n");

    printf("Percorrendo em ordem simétrica: ");
    percorrerOrdemSimetrica(root);
    printf("\n");

    printf("Percorrendo em pós-ordem: ");
    percorrerPosOrdem(root);
    printf("\n");

    // Mínimo e Máximo
    printf("Valor mínimo na árvore: %d\n", minimo(root));
    printf("Valor máximo na árvore: %d\n", maximo(root));

    // Liberar memória
    liberarArvore(root);

    return 0;
}