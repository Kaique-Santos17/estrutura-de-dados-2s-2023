#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

// Funções principais
TreeNode* inserir(TreeNode* root, int valor);
TreeNode* remover(TreeNode* root, int valor);
int buscar(TreeNode* root, int valor);
void percorrerPreOrdem(TreeNode* root);
void percorrerOrdemSimetrica(TreeNode* root);
void percorrerPosOrdem(TreeNode* root);
int minimo(TreeNode* root);
int maximo(TreeNode* root);

// Funções auxiliares
void liberarArvore(TreeNode* root);

#endif