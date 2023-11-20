#include "arvorebinaria.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode* criarNo(int valor) {
    TreeNode* novoNo = (TreeNode*)malloc(sizeof(TreeNode));
    if (novoNo != NULL) {
        novoNo->key = valor;
        novoNo->left = NULL;
        novoNo->right = NULL;
    }
    return novoNo;
}

TreeNode* inserir(TreeNode* root, int valor) {
    if (root == NULL) {
        return criarNo(valor);
    }

    if (valor < root->key) {
        root->left = inserir(root->left, valor);
    } else if (valor > root->key) {
        root->right = inserir(root->right, valor);
    }

    return root;
}

TreeNode* encontrarMinimo(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

TreeNode* remover(TreeNode* root, int valor) {
    if (root == NULL) {
        return root;
    }

    if (valor < root->key) {
        root->left = remover(root->left, valor);
    } else if (valor > root->key) {
        root->right = remover(root->right, valor);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = encontrarMinimo(root->right);
        root->key = temp->key;
        root->right = remover(root->right, temp->key);
    }

    return root;
}

int buscar(TreeNode* root, int valor) {
    if (root == NULL) {
        return 0;
    }

    if (root->key == valor) {
        return 1;
    }

    if (valor < root->key) {
        return buscar(root->left, valor);
    } else {
        return buscar(root->right, valor);
    }
}

void percorrerPreOrdem(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        percorrerPreOrdem(root->left);
        percorrerPreOrdem(root->right);
    }
}

void percorrerOrdemSimetrica(TreeNode* root) {
    if (root != NULL) {
        percorrerOrdemSimetrica(root->left);
        printf("%d ", root->key);
        percorrerOrdemSimetrica(root->right);
    }
}

void percorrerPosOrdem(TreeNode* root) {
    if (root != NULL) {
        percorrerPosOrdem(root->left);
        percorrerPosOrdem(root->right);
        printf("%d ", root->key);
    }
}

int minimo(TreeNode* root) {
    if (root == NULL) {
        printf("Árvore vazia. Não há valor mínimo.\n");
        return -1; // ou outro valor que represente a ausência de mínimo
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root->key;
}

int maximo(TreeNode* root) {
    if (root == NULL) {
        printf("Árvore vazia. Não há valor máximo.\n");
        return -1; // ou outro valor que represente a ausência de máximo
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root->key;
}

void liberarArvore(TreeNode* root) {
    if (root != NULL) {
        liberarArvore(root->left);
        liberarArvore(root->right);
        free(root);
    }
}