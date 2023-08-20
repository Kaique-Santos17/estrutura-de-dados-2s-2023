#include <stdio.h>

int conta_int_array(int array[], int tamanho, int busca) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == busca) {
            contador++;
        }
    }
    return contador;
}

int main() {
    int meu_array[] = {5, 7, 9, 6, 7, 11, 6, 5};
    int tamanho = sizeof(meu_array) / sizeof(meu_array[0]);
    int busca = 7;

    int resultado = conta_int_array(meu_array, tamanho, busca);
    printf("Saída: %d\n", resultado);

    return 0;
}